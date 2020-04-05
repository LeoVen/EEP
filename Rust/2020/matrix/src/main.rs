use find_folder::Search;
use piston_window::*;
use rand::Rng;

const STEP: f64 = 15.0;
const WIDTH: f64 = 640.0;
const HEIGHT: f64 = 480.0;
const LMAX: u64 = 80;

struct Rain {
    chars: Vec<char>,
    opacity: f32,
    x: f64,
    y: f64,
    timer: f64,
    max: f64,
}

impl Rain {
    fn next<R: Rng + ?Sized>(&mut self, rng: &mut R) {
        self.chars.remove(0);

        self.y += STEP;

        self.add(rng);
    }

    fn add<R: Rng + ?Sized>(&mut self, rng: &mut R) {
        let seed: u32 = (rng.gen::<u32>() % 94) + 33;

        let c = std::char::from_u32(seed).unwrap();

        self.chars.push(c);
    }

    fn new<R: Rng + ?Sized>(rng: &mut R, ry: bool) -> Rain {
        let y;

        let l = (rng.gen::<usize>() % 12) + 5;

        if ry {
            y = rng.gen::<f64>() * HEIGHT;
        } else {
            y = -(l as f64) * STEP;
        }

        let mut result = Rain {
            chars: Vec::new(),
            x: rng.gen::<f64>() * WIDTH,
            y: y,
            max: (rng.gen::<f64>() * 0.1) + 0.05,
            opacity: (rng.gen::<f32>() * 0.7),
            timer: 0.0,
        };

        for _ in 0..l {
            result.add(rng);
        }

        result
    }

    fn many<R: Rng + ?Sized>(rng: &mut R) -> Vec<Rain> {
        let mut result: Vec<Rain> = Vec::new();

        for _ in 0..LMAX {
            result.push(Rain::new(rng, true));
        }

        result
    }
}

fn main() {
    let mut rng = rand::thread_rng();

    let mut window: PistonWindow = WindowSettings::new("Matrix Rain", (WIDTH, HEIGHT))
        .exit_on_esc(true)
        .build()
        .unwrap();

    let mut path = Search::Parents(3).for_folder("assets").unwrap();

    path.push("FiraCode-Regular.ttf");

    println!("Constructed file path : {:?}", path);

    let mut glyphs = window.load_font(path).unwrap();

    let mut rains = Rain::many(&mut rng);
    let mut buffer = String::new();

    while let Some(e) = window.next() {
        // update
        e.update(|u| {
            for i in 0..rains.len() {
                rains[i].timer += u.dt;
                if rains[i].timer >= rains[i].max {
                    rains[i].timer -= rains[i].max;
                    rains[i].next(&mut rng);
                    if rains[i].y > HEIGHT {
                        rains.remove(i);
                        rains.push(Rain::new(&mut rng, false));
                    }
                }
            }
        });

        // draw
        window.draw_2d(&e, |c, g, d| {
            // c - Context
            // g - G2d
            // d - Device
            clear([0.0, 0.0, 0.0, 1.0], g);
            for r in rains.iter() {
                for j in 0..r.chars.len() {
                    buffer.clear();
                    buffer.push(r.chars[j]);
                    let transform = c
                        .transform
                        .trans(r.x, r.y + (STEP * j as f64));
                    text(
                        [0.0, 1.0, 0.0, r.opacity],
                        STEP as u32,
                        buffer.as_str(),
                        &mut glyphs,
                        transform,
                        g,
                    )
                    .unwrap();
                }
            }
            glyphs.factory.encoder.flush(d)
        });
    }
}
