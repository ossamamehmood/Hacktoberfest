import React, { useState } from "react";

import Card from "../UI/Card";
import "./IngredientForm.css";
import LoadingIndicator from '../../components/UI/LoadingIndicator'
const IngredientForm = React.memo((props) => {


  const [enteredtitle, setenteredtitle] = useState("");
  const [amt, setenteredamt] = useState("");

  const submitHandler = (event) => {
    event.preventDefault();
    props.onaddingedrient({title:enteredtitle,amount:amt})
    // ...
  };

  return (
    <section className="ingredient-form">
      <Card>
        <form onSubmit={submitHandler}>
          <div className="form-control">
            <label htmlFor="title">Name</label>
            <input
              type="text"
              id="title"
              value={enteredtitle}
              onChange={(event) => {
                const newtitle = event.target.value;
                setenteredtitle(newtitle);
              }}
            />
          </div>
          <div className="form-control">
            <label htmlFor="amount">Amount</label>
            <input
              type="number"
              id="amount"
              value={amt}
              onChange={(event) => {
                const newamount = event.target.value;
                setenteredamt(newamount);
              }}
            />
          </div>
          <div className="ingredient-form__actions">
            <button type="submit">Add Ingredient</button>
            {props.loading && <LoadingIndicator></LoadingIndicator>}
          </div>
        </form>
      </Card>
    </section>
  );
});

export default IngredientForm;
