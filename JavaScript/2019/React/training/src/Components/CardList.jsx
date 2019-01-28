import React from "react";

const Card = (props) => {
    return (
        <div style={{margin: '1em'}}>
            <img width="75" src={props.avatar_url} alt={props.name}/>
            <div style={{display: 'inline-block', marginLeft: 10}}>
                <div style={{fontSize: '1.25em', fontWeight: 'bold'}}>
                    {props.name}
                </div>
                <div>{props.company}</div>
            </div>
        </div>
    );
};

export const CardList = (props) => {
    return (
        <div>
            {props.cards.map((card, i) => <Card key={`cards-${i}`} {...card} />)}
        </div>
    );
};