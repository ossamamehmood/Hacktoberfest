document.addEventListener("DOMContentLoaded", () => {
  const grid = document.querySelector(".grid");
  let width = 10;
  let squares = [];
  let bombCount = 20;
  let isGameOver = false;
  let flags = 0;
  const restart = document.getElementById("restart");
  let shuffledArray;
  // create board
  function createBoard() {
    isGameOver = false;
    document.getElementById('result').innerHTML = '';
    grid.innerHTML = "";
    squares = [];
    // get shuffled game array with random bombs
    const bombsArray = Array(bombCount).fill("bomb");
    const emptyArray = Array(width * width - bombCount).fill("valid");

    const gameArray = emptyArray.concat(bombsArray);

    shuffledArray = gameArray.sort(() => Math.random() - 0.5);

    for (let i = 0; i < width * width; i++) {
      const square = document.createElement("div");
      square.setAttribute("id", i);
      // console.log(square);
      // square.classList.add(shuffledArray[i]);
      grid.appendChild(square);
      squares.push(square);

      // normal click
      square.addEventListener("click", function (e) {
        click(square);
      });

      // cntrl and left click
      square.oncontextmenu = function (e) {
        e.preventDefault();
        addFlag(square);
      };
    }

    // add Numbers
    for (let i = 0; i < squares.length; i++) {
      let total = 0;
      const isLeftEdge = i % width === 0;
      const isRightEdge = i % width === width - 1;

      if (shuffledArray[i] == "valid") {
        if (i > 0 && !isLeftEdge && shuffledArray[i-1] == "bomb")
          total++;
        if (i > 9 && !isRightEdge && shuffledArray[i + 1 - width] == "bomb")
          total++;
        if (i > 10 && shuffledArray[i - width] == "bomb")
           total++;
        if (
          i > 11 &&
          !isLeftEdge &&
          shuffledArray[i - 1 - width] == "bomb"
        )
          total++;
        if (i < 98 && !isRightEdge && shuffledArray[i + 1] == "bomb")
          total++;
        if (
          i < 90 &&
          !isLeftEdge &&
          shuffledArray[i - 1 + width] == "bomb"
        )
          total++;
        if (
          i < 88 &&
          !isRightEdge &&
          shuffledArray[i + 1 + width] == "bomb"
        )
          total++;
        if (i < 89 && shuffledArray[i + width] == "bomb") total++;
        squares[i].setAttribute("data", total);
      }else{
        squares[i].setAttribute("data", 0);
      }
    }
  }

  // add Flag With Right Click
  function addFlag(square) {
    if (isGameOver) return;
    if (!square.classList.contains("checked") && flags < bombCount) {
      if (!square.classList.contains("flag")) {
        square.classList.add("flag");
        square.innerHTML = `<i class="fa fa-flag" aria-hidden="true"></i>`;
        flags++;
        checkForWin();
      } else {
        square.classList.remove("flag");
        square.innerHTML = "";
        flags--;
      }
    }
  }

  createBoard();

  function click(square) {
    let currentId = square.id;
    if (isGameOver){
      return;
    }
    if (
      square.classList.contains("checked") ||
      square.classList.contains("flag")
    )
      return;
    if (shuffledArray[currentId] == "bomb") {
      gameOver(square);
      return;
    } else {
      let total = square.getAttribute("data");
      if (total != 0) {
        square.classList.add("checked");
        square.innerHTML = total;
        return;
      }
      checkSquare(square, currentId);
    }
    square.classList.add("checked");
    checkForWin();
  }

  // checking neighnouring squares
  function checkSquare(square, currentId) {
    const isLeftEdge = currentId % width === 0;
    const isRightEdge = currentId % width === width - 1;

    setTimeout(() => {
      if (currentId > 0 && !isLeftEdge) {
        const newId = squares[parseInt(currentId) - 1].id;
        const newSquare = document.getElementById(newId);
        click(newSquare);
      }
      if (currentId > 9 && !isRightEdge) {
        const newId = squares[parseInt(currentId) + 1 - width].id;
        const newSquare = document.getElementById(newId);
        click(newSquare);
      }
      if (currentId > 10) {
        const newId = squares[parseInt(currentId) - width].id;
        const newSquare = document.getElementById(newId);
        click(newSquare);
      }
      if (currentId > 11 && !isLeftEdge) {
        const newId = squares[parseInt(currentId) - 1 - width].id;
        const newSquare = document.getElementById(newId);
        click(newSquare);
      }
      if (currentId < 98 && !isRightEdge) {
        const newId = squares[parseInt(currentId) + 1].id;
        const newSquare = document.getElementById(newId);
        click(newSquare);
      }

      if (currentId < 90 && !isLeftEdge) {
        const newId = squares[parseInt(currentId) - 1 + width].id;
        const newSquare = document.getElementById(newId);
        click(newSquare);
      }
      if (currentId < 88 && !isRightEdge) {
        const newId = squares[parseInt(currentId) + 1 + width].id;
        const newSquare = document.getElementById(newId);
        click(newSquare);
      }
      if (currentId < 89) {
        const newId = squares[parseInt(currentId) + width].id;
        const newSquare = document.getElementById(newId);
        click(newSquare);
      }
    }, 10);
  }

  function gameOver(square) {
    isGameOver = true;

    // show all bombs
    squares.forEach((sq) => {
      if (shuffledArray[sq.id] == "bomb") {
        sq.innerHTML = '<i class="fa fa-bomb" aria-hidden="true"></i>';
        sq.classList.add("exploded");
      }
    });
    document.getElementById('result').innerHTML = 'You lose!!!!!!!';
  }

  function checkForWin() {
    let matches = 0, emptySquares = 0;
    for (let i = 0; i < squares.length; i++) {
      if (
        shuffledArray[i] == "bomb" &&
        squares[i].classList.contains("flag")
      ) {
        matches++;
      }
      if(shuffledArray[i] == "valid" && squares[i].classList.contains("checked"))
        emptySquares++;
      if (matches == bombCount || emptySquares == 100 - bombCount) {
        document.getElementById('result').innerHTML = "You Win!!!!!!!!!!!!!!";
        isGameOver = true;
      }
    }
  }

  restart.addEventListener("click", function (e) {
    e.preventDefault();
    createBoard();
  });
});
