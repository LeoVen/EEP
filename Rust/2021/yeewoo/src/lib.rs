#![recursion_limit = "512"]

use wasm_bindgen::prelude::*;
use yew::events::MouseEvent;
use yew::prelude::*;

struct Model {
    link: ComponentLink<Self>,
    /// Current counter value
    value: i64,
    /// How much the counter changes at every click
    change: i64,
}

enum Msg {
    ChangeCounter(i64),
}

impl Component for Model {
    type Message = Msg;
    type Properties = ();

    fn create(_: Self::Properties, link: ComponentLink<Self>) -> Self {
        Self {
            link,
            value: 0,
            change: 1,
        }
    }

    fn update(&mut self, msg: Self::Message) -> ShouldRender {
        match msg {
            Msg::ChangeCounter(value) => self.value += value,
        }
        true
    }

    fn change(&mut self, _props: Self::Properties) -> ShouldRender {
        // Should only return "true" if new properties are different to
        // previously received properties.
        // This component has no properties so we will always return "false".
        false
    }

    fn view(&self) -> Html {
        let change = self.change;
        let value = self.value;

        let colors = if value > 0 {
            html! {
                <div style="display: flex; flex-wrap: wrap; font-family: monospace;">
                    { (0..value).into_iter().map(|red|
                        (0..value).into_iter().map(move |green| {
                            (0..value).into_iter().map(move |blue| {
                                html! {
                                    <div style=&format!("background-color: rgb({}, {}, {}); padding: 2px;", red, green, blue)></div>
                                }
                            })
                        })
                    ).flatten().flatten().collect::<Html>() }
                </div>
            }
        } else {
            html! { <p> {"No happy colors :("} </p> }
        };

        html! {
            <div>
                <button style="padding: 0.2em 1em; margin: 4px;"
                        onclick=self.link.callback(move |_| Msg::ChangeCounter(change))
                        oncontextmenu=self.link.callback(move |e: MouseEvent| {
                            e.prevent_default();
                            Msg::ChangeCounter(-change)
                        })
                        onwheel=self.link.callback(|e: WheelEvent| {
                            e.prevent_default();
                            let y = e.delta_y();
                            Msg::ChangeCounter((-y / 100.0) as i64)
                        })>
                        <p> { change } </p>
                </button>
                <p>{ value }</p>
                <p> {"Total Colors:"}{ value.pow(3) } </p>
                {colors}
            </div>
        }
    }
}

#[wasm_bindgen(start)]
pub fn run_app() {
    App::<Model>::new().mount_to_body();
}
