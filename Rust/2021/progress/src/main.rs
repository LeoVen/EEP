const CLEAR: &str = "\x1B[2J\x1B[1;1H";

struct Unbounded;
struct Bounded {
    bound: usize,
    delim: (char, char),
}

struct Progress<Iter, Bound> {
    iter: Iter,
    bound: Bound,
    i: usize,
}

trait ProgressIteratorExt: Sized {
    fn progress(self) -> Progress<Self, Unbounded>;
}

trait ProgressDisplay: Sized {
    fn display<Iter>(&self, progress: &Progress<Iter, Self>);
}

impl ProgressDisplay for Unbounded {
    fn display<Iter>(&self, progress: &Progress<Iter, Self>) {
        println!("{}", "#".repeat(progress.i));
    }
}

impl ProgressDisplay for Bounded {
    fn display<Iter>(&self, progress: &Progress<Iter, Self>) {
        println!(
            "{}{}{}{}",
            self.delim.0,
            "#".repeat(progress.i),
            " ".repeat(self.bound - progress.i),
            self.delim.1,
        )
    }
}

impl<Iter> ProgressIteratorExt for Iter {
    fn progress(self) -> Progress<Self, Unbounded> {
        Progress::new(self)
    }
}

impl<Iter> Progress<Iter, Unbounded> {
    pub fn new(iter: Iter) -> Self {
        Progress {
            iter,
            bound: Unbounded,
            i: 1,
        }
    }
}

impl<Iter> Progress<Iter, Unbounded>
where
    Iter: ExactSizeIterator,
{
    pub fn with_bound(self) -> Progress<Iter, Bounded> {
        let bound = Bounded {
            bound: self.iter.len(),
            delim: ('[', ']'),
        };
        Progress {
            iter: self.iter,
            bound,
            i: 0,
        }
    }
}

impl<Iter> Progress<Iter, Bounded> {
    pub fn with_delims(mut self, delim: (char, char)) -> Self {
        self.bound.delim = delim;
        self
    }
}

impl<Iter, Bound> Iterator for Progress<Iter, Bound>
where
    Iter: Iterator,
    Bound: ProgressDisplay,
{
    type Item = Iter::Item;

    fn next(&mut self) -> Option<Self::Item> {
        print!("{}", CLEAR);
        self.bound.display(&self);
        self.i += 1;
        self.iter.next()
    }
}

fn expensive_function(_: usize) {
    std::thread::sleep(std::time::Duration::from_secs(1));
}

fn main() {
    let data = vec![0, 1, 2, 3, 4, 5, 6, 7, 8, 9];

    for i in data.iter().progress().with_bound().with_delims(('{', '}')) {
        expensive_function(*i);
    }

    for i in (0..).progress() {
        expensive_function(i);
    }
}
