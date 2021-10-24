use piston_window::types::{Color, Rectangle};
use piston_window::*;

const WIDTH: f64 = 400.0;
const HEIGHT: f64 = 800.0;

const COLOR_BG: Color = [1.0, 1.0, 1.0, 1.0];
const COLOR_BALL: Color = [0.0, 0.0, 0.0, 1.0];

const BALL_SIZE: f64 = 100.0;

pub struct Vec2 {
    pub x: f64,
    pub y: f64,
}

pub struct Ball {
    pub pos: Vec2,
    pub vel: Vec2,
    pub w: f64,
    pub h: f64,
}

// Pixels per second^2
const GRAVITY: f64 = 9.807;
// Simulation speed
const PIXEL_ACCELERATION: f64 = 10.0;

impl Ball {
    pub fn gravity(&mut self, dt: f64) {
        const GRAV: Vec2 = Vec2 { x: 0.0, y: GRAVITY };
        self.vel.x += GRAV.x * dt * PIXEL_ACCELERATION;
        self.vel.y += GRAV.y * dt * PIXEL_ACCELERATION;
    }
    pub fn velocity(&mut self, dt: f64) {
        self.pos.x += self.vel.x * dt * PIXEL_ACCELERATION;
        self.pos.y += self.vel.y * dt * PIXEL_ACCELERATION;
    }
    pub fn center_rect(&self) -> Rectangle<f64> {
        center_on(self.pos.x, self.pos.y, self.w, self.h)
    }
}

pub fn center_on(x: f64, y: f64, w: f64, h: f64) -> Rectangle<f64> {
    [x - w / 2.0, y - h / 2.0, w, h]
}

fn main() {
    let mut window: PistonWindow = WindowSettings::new("Physics", [WIDTH, HEIGHT])
        .exit_on_esc(true)
        .build()
        .unwrap();

    let mut events = window.events;
    let mut ball = Ball {
        pos: Vec2 {
            x: WIDTH / 2.0,
            y: HEIGHT / 4.0,
        },
        vel: Vec2 { x: 0.0, y: 0.0 },
        w: BALL_SIZE,
        h: BALL_SIZE,
    };

    while let Some(e) = events.next(&mut window) {
        window.draw_2d(&e, |c, g, _d| {
            clear(COLOR_BG, g);
            // [r, g, b, a]; [x, y, w, h]
            ellipse(COLOR_BALL, ball.center_rect(), c.transform, g);
        });
        e.update(|arg| {
            let dt = arg.dt;
            if ball.pos.y + ball.h / 2.0 > HEIGHT {
                ball.vel.x = -(ball.vel.x.abs()) * 0.8;
                ball.vel.y = -(ball.vel.y.abs()) * 0.8;
            } else {
                ball.gravity(dt);
            }
            ball.velocity(dt);
        });
    }
}
