import React from "react";

class Form extends React.Component {

    render() {
        return (
            <form>
                <input type="text" placeholder="Github Username"/>
                <button type="submit">Add card</button>
            </form>
        );
    }
}