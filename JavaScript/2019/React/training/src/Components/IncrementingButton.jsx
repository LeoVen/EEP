import React from "react";

export const ButtonResult = (props) => {
    return (
        <div>{props.counter}</div>
    );
};

export class IncrementingButton extends React.Component {
    handleClick = () => {
        this.props.onClickFunction(this.props.incrementValue);
    };

    render() {
        return (
            <div>
                <button onClick={this.handleClick} className="btn red">
                    +{this.props.incrementValue}
                </button>
            </div>
        );
    }
}