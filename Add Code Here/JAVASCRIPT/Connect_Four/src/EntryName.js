import react, { usestate } from "react";
import "./entryName.css";
import { Outlet, Link } from "react-router-dom";

function EntryName({ Initialiser }) {
  function Submit() {
    let round = prompt("Number of games");
    let name1 = document.getElementById("name_player1").value;
    let name2 = document.getElementById("name_player2").value;
    Initialiser(name1, name2, round);
  }

  return (
    <div className="details">
      <div className="player1">
        <form>
          <label>
            Player 01
            <br />
            <br />
            <input type="text" id="name_player1" name="plyr1" />
          </label>
        </form>
      </div>
      <div className="player2">
        <form>
          <label>
            Player 02
            <br />
            <br />
            <input type="text" id="name_player2" name="plyr2" />
          </label>
        </form>
      </div>
      <div className="line"></div>
          <Link to="/Screen_2">
            <button
              className="button"
              type="submit"
              onClick={() => {
                Submit();
              }}
            >
              Start Game
            </button>
          </Link>
    </div>
  );
}

export default EntryName;
