import "./screen_2.css";
import ConnectFour from "./ConnectFour";

function Screen_2(data) {
  console.log(data);
  return (
    <div className="screen_2">
      <div className="main_box">
        <div className="game_table">
          <ConnectFour
            name1={data.name1}
            name2={data.name2}
            judge={data.judge}
            counter={data.counter}
            endGame={data.endGame}
          />
        </div>
        <div className="score_table">
          <div className="game_3">{data.round} Games Tournament</div>
          <div className="playga">{data.endGame?<span style={{fontSize:20,fontWeight:900,color:'#FF6363', textTransform:'capitalize'}}>Congratulation {data.winner}</span>:<>Playing Game {data.roundPlayed+1}</>}</div>
          <div className="details1">
            <div className="player1">
              <form>
                <div style={{ display: "flex", flexDirection: "row" }}>
                  <div
                    style={{
                      width: "50%",
                      display: "flex",
                      justifyContent: "center",
                      alignItems: "center",
                    }}
                  >
                    <label>
                      Player 01
                      <br />
                      <span
                        style={{
                          color: "black",
                          fontWeight: 900,
                          fontSize: 25,
                          textTransform: "uppercase",
                        }}
                      >
                        {data.name1}
                      </span>
                    </label>
                  </div>
                  <div
                    style={{
                      width: "50%",
                      display: "flex",
                      justifyContent: "center",
                      alignItems: "center",
                    }}
                  >
                    <label>
                      Score
                      <br />
                      <span
                        style={{
                          color: "black",
                          fontWeight: 900,
                          fontSize: 25,
                          textTransform: "uppercase",
                        }}
                      >
                        {data.score1}
                      </span>
                    </label>
                  </div>
                </div>
              </form>
            </div>
            <div className="player2">
              <form>
                <div style={{ display: "flex", flexDirection: "row" }}>
                  <div
                    style={{
                      width: "50%",
                      display: "flex",
                      justifyContent: "center",
                      alignItems: "center",
                    }}
                  >
                    <label>
                      Player 01
                      <br />
                      <span
                        style={{
                          color: "black",
                          fontWeight: 900,
                          fontSize: 25,
                          textTransform: "uppercase",
                        }}
                      >
                        {data.name2}
                      </span>
                    </label>
                  </div>
                  <div
                    style={{
                      width: "50%",
                      display: "flex",
                      justifyContent: "center",
                      alignItems: "center",
                    }}
                  >
                    <label>
                      Score
                      <br />
                      <span
                        style={{
                          color: "black",
                          fontWeight: 900,
                          fontSize: 25,
                          textTransform: "uppercase",
                        }}
                      >
                        {data.score2}
                      </span>
                    </label>
                  </div>
                </div>
              </form>
            </div>
          </div>
        </div>
      </div>
    </div>
  );
}

export default Screen_2;
