use piston_window::*;
use rand::*;

const WIDTH : f64 = 1280.0;
const HEIGHT : f64 = 720.0;

/// A bubble from the lava lamp
struct Bubble {
    /// Speed of the bubble
    speed: f64,
    /// X position of the bubble
    x: f64,
    /// Y position of the bubble
    y: f64,
    /// Radius of the bubble
    r: f64,
}

impl Bubble {
    pub fn new(num: Option<f64>) -> Bubble {

        let r = (random::<f64>() * (WIDTH / 10.0)) + 5.0;

        let mut b: Bubble = Bubble {
            speed: (random::<f64>() * 200.0) + 20.0,
            y: random::<f64>() * (HEIGHT + r),
            x: random::<f64>() * (WIDTH + r),
            r: r,
        };

        if let Some(y) = num {
            b.speed = 0.0;
            b.y = y
        }

        b
    }
}

fn get_bubbles() -> Vec<Bubble> {
    let mut bubbles = Vec::new();

    let n = (random::<u64>() % 30) + 10;

    for _ in 0..n {
        bubbles.push(Bubble::new(Some(HEIGHT)));
        bubbles.push(Bubble::new(Some(0.0)));
        bubbles.push(Bubble::new(None));
    }

    bubbles
}

fn main() {
    let bub = [1.0, 97.0 / 255.0, 0.0, 1.0];
    let bg = [104.0 / 255.0, 221.0 / 255.0, 19.0 / 255.0, 1.0];

    let mut bubbles : Vec<Bubble> = get_bubbles();

    let mut window : PistonWindow = WindowSettings::new("Lava Lamp", [WIDTH, HEIGHT])
        .exit_on_esc(true).build().unwrap();

    let mut events = window.events;

    while let Some(e) = events.next(&mut window) {
        if let Some(_) = e.render_args() {
            let bubbles = &bubbles;
            window.draw_2d(&e, |c, g, _| {
                clear(bg, g);
                for b in bubbles {
                    ellipse(bub, [b.x - b.r, b.y - b.r, b.r * 2.0, b.r * 2.0], c.transform, g)
                }
            });
        }
        if let Some(u) = e.update_args() {
            let bubbles = &mut bubbles;
            for b in bubbles {
                b.y -= b.speed * u.dt;
                if b.y + b.r <= 0.0 {
                    b.y = HEIGHT
                }
            }
        }
    }
}