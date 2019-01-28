import React, { Component } from 'react';
import './App.css'
import { ButtonResult , IncrementingButton } from "./Components/IncrementingButton";
import { CardList } from "./Components/CardList";

class App extends Component {
    state = {
        counter: 0,
        cards: [
            { name: "Paul O’Shannessy",
                avatar_url: "https://avatars.githubusercontent.com/u/8445?v=3",
                company: "Facebook"
            },
            { name: "Ben Alpert",
                avatar_url: "https://avatars.githubusercontent.com/u/6820?v=3",
                company: "Facebook"
            },
        ]
    };

    incrementCounter = (incrementValue) => {
        this.setState((prevState) => ({
            counter: prevState.counter + incrementValue
        }));
    };

    render() {
        return (
          <div>
              <div className="flex-buttons">
                  {[1, 5, 10, 50, 100, 1000, 5000, 10000, 100000, 1000000].map((value, i) => {
                      return <IncrementingButton key={`inc-btn-${i}`} incrementValue={value} onClickFunction={this.incrementCounter}/>
                  })}
              </div>
              <ButtonResult counter={this.state.counter}/>
              <div>
                  <CardList cards={this.state.cards}/>
              </div>
          </div>
        );
  }
}

export default App;
