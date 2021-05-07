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
                        { change }
                </button>
                <p>{ self.value }</p>
                <div style="display: flex; flex-wrap: wrap; font-family: monospace;">
                    { (0..255).into_iter().map(|num|
                        html! {
                            <div style=&format!(
                                "background-color: rgb({0}, {0}, {0}); padding: 1em;", num
                            )>{format!("#{0:02x}{0:02x}{0:02x}", num)}</div>
                        }
                    ).collect::<Html>() }
                </div>
            </div>
        }
    }
}

#[wasm_bindgen(start)]
pub fn run_app() {
    App::<Model>::new().mount_to_body();
}
