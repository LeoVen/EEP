extern crate rand;

use rand::Rng;
use std::cmp::{Eq, PartialEq};

const TOTAL_RUNS: usize = 5;

const INITIAL_POPULATION_SIZE: usize = 1000;
const NUMBER_OF_GENERATIONS: usize = 1000;
const KNAPSACK_WEIGHT_CAPACITY: usize = 6404180;

const MAX_NUMBER_TO_SELECT_TO_REPRODUCE: usize = 100;

const MUTATION_CHANCE: f64 = 0.1;
const MUTATION_RATE: usize = 2;

const TOTAL_ITEMS: usize = 26;

// Weight and value of an item
const KNAPSACK_ITEMS: [[usize; 2]; TOTAL_ITEMS] = [
    [32252, 68674],
    [225790, 471010],
    [468164, 944620],
    [489494, 962094],
    [35384, 78344],
    [265590, 579152],
    [497911, 902698],
    [800493, 1686515],
    [823576, 1688691],
    [552202, 1056157],
    [323618, 677562],
    [382846, 833132],
    [44676, 99192],
    [169738, 376418],
    [610876, 1253986],
    [854190, 1853562],
    [671123, 1320297],
    [698180, 1301637],
    [446517, 859835],
    [909620, 1677534],
    [904818, 1910501],
    [730061, 1528646],
    [931932, 1827477],
    [952360, 2068204],
    [926023, 1746556],
    [978724, 2100851],
];

#[derive(Clone, Copy, PartialEq, Eq)]
enum ItemState {
    ItemGoesIn,
    ItemGoesOut,
}

impl ItemState {
    fn random() -> ItemState {
        match rand::thread_rng().gen::<bool>() {
            true => ItemState::ItemGoesIn,
            false => ItemState::ItemGoesOut,
        }
    }

    fn inverse(item: ItemState) -> ItemState {
        match item {
            ItemState::ItemGoesIn => ItemState::ItemGoesOut,
            ItemState::ItemGoesOut => ItemState::ItemGoesIn,
        }
    }
}

// Represents an individual in the genetic algorithm
#[derive(PartialEq, Clone)]
struct KSItem {
    // A list of all items' states (if they go in or out)
    pub items: Vec<ItemState>,

    // The individual fitness
    pub fit: usize,

    // The individual probability of being selected for reproduction
    pub prob: f64,
}

impl KSItem {
    fn new(items: Vec<ItemState>) -> KSItem {
        KSItem {
            items: Vec::from(items),
            fit: 0,
            prob: 0.0,
        }
    }

    fn crossover(item1: &KSItem, item2: &KSItem) -> KSItem {
        let mut rng = rand::thread_rng();

        let xpoint: usize = rng.gen_range(0, TOTAL_ITEMS);

        let mut items = Vec::from(&item1.items[xpoint..]);

        items.append(&mut Vec::from(&item2.items[..xpoint]));

        KSItem {
            fit: 0,
            prob: 0.0,
            items: items,
        }
    }
}

fn generate_initial_population() -> Vec<KSItem> {
    let mut population = Vec::<KSItem>::with_capacity(INITIAL_POPULATION_SIZE);

    for _ in 0..INITIAL_POPULATION_SIZE {
        let items: Vec<ItemState> = (0..TOTAL_ITEMS).map(|_| ItemState::random()).collect();
        population.push(KSItem::new(items));
    }

    population
}

fn calculate_population_fitness(population: Vec<KSItem>) -> (Vec<KSItem>, usize) {
    let mut best_fit = 0;
    let mut result = Vec::<KSItem>::new();

    for mut individual in population.into_iter() {
        match calculate_individual_fitness(&individual) {
            Some(fit) => {
                if fit > best_fit {
                    best_fit = fit;
                }
                individual.fit = fit;
                result.push(individual);
            }
            None => {}
        }
    }

    (result, best_fit)
}

fn calculate_individual_fitness(individual: &KSItem) -> Option<usize> {
    let mut total_weight = 0;
    let mut total_value = 0;

    for (i, gene) in individual.items.iter().enumerate() {
        match gene {
            ItemState::ItemGoesIn => {
                total_weight += KNAPSACK_ITEMS[i][0];
                total_value += KNAPSACK_ITEMS[i][1];
            }
            ItemState::ItemGoesOut => {}
        }
    }

    if total_weight > KNAPSACK_WEIGHT_CAPACITY {
        return None;
    }

    Some(total_value)
}

fn set_probabilities(population: &mut Vec<KSItem>) {
    let population_sum: f64 = population
        .iter()
        .fold(0f64, |sum, val| sum + val.fit as f64);
    for item in population {
        item.prob = item.fit as f64 / population_sum;
    }
}

fn roulette_wheel_selection(population: &mut Vec<KSItem>) -> Vec<KSItem> {
    set_probabilities(population);
    let mut chosen_ones = Vec::<KSItem>::new();

    let mut rng = rand::thread_rng();

    for _ in 0..MAX_NUMBER_TO_SELECT_TO_REPRODUCE {
        let r: f64 = rng.gen();
        for individual in population.iter() {
            if r <= individual.prob {
                chosen_ones.push(individual.clone());
                break;
            }
        }
    }

    chosen_ones
}

fn reproduce_children(chosen_ones: Vec<KSItem>) -> Vec<KSItem> {
    let mut children = Vec::<KSItem>::new();

    for parent_index in 0..(chosen_ones.len() / 2) {
        children.push(KSItem::crossover(
            &chosen_ones[parent_index],
            &chosen_ones[parent_index + 1],
        ));
    }

    children
}

fn mutate_children(children: Vec<KSItem>) -> Vec<KSItem> {
    let mut result = Vec::new();

    for mut child in children.into_iter() {
        let mut rng = rand::thread_rng();

        let r: f64 = rng.gen();

        if r <= MUTATION_CHANCE {
            for _ in 0..MUTATION_RATE {
                let random_index: usize = rng.gen_range(0, TOTAL_ITEMS);
                child.items[random_index] = ItemState::inverse(child.items[random_index]);
            }
        }

        result.push(child);
    }

    result
}

fn ga() {
    let mut best_global_fitness: usize = 0;

    let mut global_population = generate_initial_population();

    for _ in 0..NUMBER_OF_GENERATIONS {
        let (mut new_population, current_best_fitness) =
            calculate_population_fitness(global_population);

        if current_best_fitness > best_global_fitness {
            best_global_fitness = current_best_fitness;
        }

        let chosen_ones = roulette_wheel_selection(&mut new_population);

        let mut children = mutate_children(reproduce_children(chosen_ones));
        new_population.append(&mut children);

        global_population = new_population;
    }

    println!("Best Fitness : {}", best_global_fitness);
    println!("Final Population: {}\n", global_population.len());
}

fn main() {
    for _ in 0..TOTAL_RUNS {
        ga();
    }
}
