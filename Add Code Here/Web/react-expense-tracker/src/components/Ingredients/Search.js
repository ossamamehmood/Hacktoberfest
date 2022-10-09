import React, { useState, useEffect ,useRef} from "react";

import Card from "../UI/Card";
import "./Search.css";

const Search = React.memo((props) => {
  const { onloadingedrients } = props;
  const [filter, setfilter] = useState("");
   const inputref=useRef();
  useEffect(() => {
   const timer= setTimeout(() => {
      if(filter===inputref.current.value)
      {
      const query =
        filter.length === 0 ? '' : `?orderBy="title"&equalTo="${filter}"`;
      fetch(
        "firebase//ingedrients.json" +
          query
      )
        .then((response) => response.json())
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
          onloadingedrients(loadingedrients);
        });
      }
    }, 500);
    return()=>{
      clearTimeout(timer);
    }
  }, [filter, onloadingedrients,inputref]);
  return (
    <section className="search">
      <Card>
        <div className="search-input">
          <label>Filter by Title</label>
          <input
          ref={inputref}
            type="text"
            value={filter}
            onChange={(event) => setfilter(event.target.value)}
          />
        </div>
      </Card>
    </section>
  );
});

export default Search;
