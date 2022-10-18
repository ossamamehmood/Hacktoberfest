import React from "react";
import "./App.css";
import { useState } from "react";
import { BrowserRouter as Router, Routes, Route, Link } from "react-router-dom";

import EntryName from "./EntryName";
import Screen_2 from "./Screen_2";
import Layout from "./layout";

function App() {
  const [Plyr1, setPlyr1] = useState("");
  const [Plyr2, setPlyr2] = useState("");
  const [round, setRound] = useState(0);
  const [roundPlayed, setRountplayed] = useState(0);
  const [score1, setScore1] = useState(0);
  const [score2, setScore2] = useState(0);
  const [endGame, setEndGame] = useState(false);
  const [winner, setWinner] = useState("");

  const roundCounter = () => {
    setRountplayed(roundPlayed + 1);
    if (roundPlayed+1 == round) {
      getWinner();
      setEndGame(true);
    }
  };

  const getWinner = () => {
    if(score1 > score2){
      setWinner(Plyr1);
    }
    else if(score1 < score2){
      setWinner(Plyr2);
    }
  };

  const Judge = (player) => {
    if (player) {
      setScore2(score2 + 1);
    } else {
      setScore1(score1 + 1);
    }
  };

  const dataInitialiser = (name1, name2, round) => {
    setRountplayed(0);
    setScore1(0);
    setScore2(0);
    setPlyr1(name1);
    setPlyr2(name2);
    setRound(round);
    setEndGame(false);
  };
  return (
    <div className="App">
      <div className="body">
        <EntryName Initialiser={dataInitialiser} />
        <Routes>
          <Route path="/" element={<Layout data={(Plyr1, Plyr2, round)} />}>
            <Route
              path="Screen_2"
              element={
                <Screen_2
                  round={round}
                  name1={Plyr1}
                  name2={Plyr2}
                  judge={Judge}
                  roundPlayed={roundPlayed}
                  counter={roundCounter}
                  score1={score1}
                  score2={score2}
                  endGame={endGame}
                  winner={winner}
                />
              }
            />
          </Route>
        </Routes>
      </div>
    </div>
  );
}

export default App;
