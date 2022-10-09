import React, { useState, useEffect, useCallback, useReducer } from "react";

import IngredientForm from "./IngredientForm";
import Search from "./Search";
import IngredientList from "./IngredientList.js";
import ErrorModal from "../UI/ErrorModal";

const ingedrientreducer = (currentingedrient, action) => {
  switch (action.type) {
    case "SET":
      return action.ingedrient; 
    case "ADD":
      return [...currentingedrient, action.ingedrient];
    case "DELETE":
      return currentingedrient.filter((ing) => ing.id !== action.id);
    default:
      throw new Error("Should not get there!");
  }
};


const httpReducer = (curHttpState, action) => {
  switch (action.type) {
    case 'SEND':
      return { isloading: true, error: null };
    case 'RESPONSE':
      return { ...curHttpState, isloading: false };
    case 'ERROR':
      return { isloading: false, error: action.errorMessage };
    case 'CLEAR':
      return { ...curHttpState, error: null };
    default:
      throw new Error('Should not be reached!');
  }
};


function Ingredients() {

  const [httpState, dispatchHttp] = useReducer(httpReducer, {
    loading: false,
    error: null
  });
  const [useringedrients,dispatch] =useReducer(ingedrientreducer,[]);
  const [ingredient, setingedrient] = useState([]);
  const [isloading, setisloading] = useState(false);
  const [error, setiserror] = useState();
  useEffect(() => {
   dispatchHttp({type:'SEND'});
    fetch(
      "put firebase endpoint"
    )
      .then((response) => {
        dispatchHttp({type:'RESPONSE'});

        response.json();
      })
      .then((responseData) => {
        const loadingedrients = [];
        console.log(responseData);
        for (const key in responseData) {
          loadingedrients.push({
            id: key,
            title: responseData[key].items.title,
            amount: responseData[key].items.amount,
          });
        }
        setingedrient(loadingedrients);
      });
  }, []);

  const addingedrienthandler = (items) => {
    fetch(
      "put firebase endpoint",
      {
        method: "POST",
        body: JSON.stringify({ items }),
        headers: { "Content-Type": "application/json" },
      }
    )
      .then((response) => {
        return response.json();
      })
      .then((responseData) => {
        // setingedrient((prev) => [...prev, { id: responseData.name, ...items }]);
        dispatch({type:'ADD',ingedrient:{id: responseData.name, ...items}})
      });
  };

  const filteredingedrients = useCallback((loadingedrients) => {

    dispatch({type:'SET',ingedrient:loadingedrients})
  }, []);

  const RemoveItemhandler = (ingedrientid) => {
    setisloading(true);
    fetch(
      `put firebase endpoint//ingedrients/${ingedrientid}.json`,
      {
        method: "DELETE",
      }
    )
      .then((response) => {
        setisloading(false);
        dispatch({type:'DELETE',id:ingedrientid})
      })
      .catch((error) => {
        dispatchHttp({type:'ERROR',errorMessage:error})
      });
  };

  const clearerror = () => {
    setisloading(false);
    setiserror(false);
  };

  return (
    <div className="App">
      {error && <ErrorModal onClose={clearerror}>{error}</ErrorModal>}
      <IngredientForm
        onaddingedrient={addingedrienthandler}
        loading={isloading}
      />

      <section>
        <Search onloadingedrients={filteredingedrients} />
        <IngredientList
          ingredients={useringedrients}
          onRemoveItem={RemoveItemhandler}
        ></IngredientList>
      </section>
    </div>
  );
}

export default Ingredients;
