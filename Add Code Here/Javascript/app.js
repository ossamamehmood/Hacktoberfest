let init = [
    `0 4 0 0 0 0 1 7 9 
  0 0 2 0 0 8 0 5 4 
  0 0 6 0 0 5 0 0 8 
  0 8 0 0 7 0 9 1 0 
  0 5 0 0 9 0 0 3 0 
  0 1 9 0 6 0 0 4 0 
  3 0 0 4 0 0 7 0 0 
  5 7 0 1 0 0 2 0 0 
  9 2 8 0 0 0 0 6 0`,
  
    `2 0 6 0 0 0 0 4 9
  0 3 7 0 0 9 0 0 0
  1 0 0 7 0 0 0 0 6
  0 0 0 5 8 0 9 0 0
  7 0 5 0 0 0 8 0 4
  0 0 9 0 6 2 0 0 0
  9 0 0 0 0 4 0 0 1
  0 0 0 3 0 0 4 9 0
  4 1 0 0 0 0 2 0 8`,
  
    `0 0 1 7 2 5 0 0 0
  0 8 0 0 1 0 0 0 6
  2 5 0 0 0 0 1 3 0
  0 7 0 0 0 0 5 0 0
  0 0 0 1 0 6 0 0 0
  0 0 9 0 0 0 0 8 0
  0 4 5 0 0 0 0 2 9
  7 0 0 0 9 0 0 6 0
  0 0 0 6 4 8 3 0 0`,
    `8 0 0 2 0 0 0 4 6
  0 0 7 9 0 0 0 0 0
  1 0 0 0 0 0 5 0 0
  0 0 0 5 0 0 0 3 2
  4 0 8 0 0 0 7 0 1
  3 2 0 0 0 7 0 0 0
  0 0 6 0 0 0 0 0 9
  0 0 0 0 0 3 2 0 0
  2 8 0 0 0 6 0 0 3`,
    `0 0 1 3 0 0 7 0 2
  0 0 6 2 0 0 0 1 0
  0 2 0 0 0 0 0 0 4
  2 0 0 6 0 1 3 0 9
  0 0 0 0 0 0 0 0 0
  4 0 3 8 0 9 0 0 7
  1 0 0 0 0 0 0 8 0
  0 5 0 0 0 6 4 0 0
  9 0 4 0 0 8 5 0 0`,
    `0 7 1 0 3 9 0 0 0
  4 6 0 0 7 5 0 1 0
  8 3 0 0 6 0 7 0 2
  0 4 2 0 0 0 0 5 8
  6 0 0 0 0 0 9 7 0
  0 1 0 5 0 0 0 0 4
  0 0 0 0 0 8 4 6 9
  7 9 0 3 4 2 0 0 0
  5 0 0 0 0 1 3 0 0`,
    `0 0 7 0 0 1 4 0 0
  0 6 0 0 0 0 0 0 0
  2 0 5 0 0 0 0 0 0
  0 0 1 7 6 0 0 5 8
  0 0 0 0 3 0 0 0 0
  0 9 0 2 0 4 0 0 0
  0 3 0 0 5 0 0 0 9
  0 0 4 0 0 0 6 0 0
  0 5 0 0 8 0 7 2 1`,
    `6 7 0 0 0 8 0 1 0
  0 2 0 0 6 0 0 0 0
  0 0 0 0 3 0 0 0 0
  2 0 1 0 0 0 0 0 6
  4 8 0 0 0 1 7 0 0
  0 0 0 0 0 0 0 0 9
  0 0 4 5 0 0 0 0 0
  0 0 0 0 0 0 3 0 0
  0 0 3 4 0 0 8 0 2`,
    `1 0 0 0 0 7 0 9 0
  0 3 0 0 2 0 0 0 8
  0 0 9 6 0 0 5 0 0
  0 0 5 3 0 0 9 0 0
  0 1 0 0 8 0 0 0 2
  6 0 0 0 0 4 0 0 0
  3 0 0 0 0 0 0 1 0
  0 4 0 0 0 0 0 0 7
  0 0 7 0 0 0 3 0 0`,
    `8 0 6 0 0 0 0 5 2
  0 9 0 7 4 0 0 0 0
  0 7 2 6 5 8 0 3 4
  0 0 0 2 0 0 0 6 3
  9 0 3 1 6 0 0 0 7
  0 0 0 0 0 0 0 0 0
  0 0 0 5 0 0 6 0 0
  4 1 0 0 0 0 3 2 5
  5 0 7 0 0 0 0 0 8`,
  ];
  
  let delay = 0;
  const delayBox = document.querySelector(".delayBox");
  const delayBar = document.querySelector(".delayBar");
  const modal =document.querySelector(".modal")
  const message = document.querySelector(".popUp");
  let resetState = false;
  let runningState = false;
  let grid = [];
  
  function setInit() {
    let val = document.getElementById("input").value;
    if (!val) {
      popUp("cant be empty!");
      return;
    }
    updateInputGrid(val);
  }
  
  function popUp(data){
      modal.style.display = "grid";
      message.innerHTML = data;
      setTimeout(()=>{
        message.innerHTML = "";
          modal.style.display = "None";
      },2000)
  }
  
  delayBox.addEventListener("click", (e) => {
    const delayBoxPosition = delayBox.getBoundingClientRect();
    const clickPosition = e.clientX;
    let width = clickPosition - delayBoxPosition.left;
    delayBar.style.width = width + "px";
    delay = width * 2;
  });
  
  async function runSolve() {
    runningState = true;
    document.querySelector(".solve").disabled = runningState;
    document.querySelector(".submit").disabled = runningState;
    let time = new Date();
    let result = await solveSudoku(grid);
    if (result !== "reset") {
      if (result) {
        popUp(`Solved in ${(( new Date() -time)/1000).toFixed(2)} seconds`);
      } else {
        popUp("Unable to solve");
      }
    }
  
    runningState = false;
    document.querySelector(".solve").disabled = runningState;
    document.querySelector(".submit").disabled = runningState;
  }
  
  function reset() {
    if (runningState) {
      resetState = true;
      runningState = false;
    }
    document.querySelector(".solve").disabled = runningState;
    document.querySelector(".submit").disabled = runningState;
    setTimeout(updateInputGrid,delay*2)
    
  }
  
  function updateInputGrid(val) {
    let gridInput = val || init[Math.floor(Math.random() * init.length)];
    document.getElementById("input").value = gridInput;
    gridInput = gridInput.trim().split("\n");
    if (gridInput.length < 9) {
      popUp("invalid matrix");
      return;
    }
    let temp = [];
    for (let i = 0; i < gridInput.length; i++) {
      let column = gridInput[i].trim().split(" ").map(Number);
      if (column.length < 9) {
        popUp("invalid matrix");
        return;
      }
      temp.push(column);
    }
    grid = temp;
    let mainGrid = document.getElementById("mainGrid");
    mainGrid.innerHTML = "";
    for (let i = 0; i < 9; i++) {
      let row = document.createElement("div");
      row.classList.add("gridRow");
      for (let j = 0; j < 9; j++) {
        let column = document.createElement("div");
        column.setAttribute("id", `${i}${j}`);
        column.classList.add("box");
        column.innerText = grid[i][j] || "";
        if (grid[i][j]) {
          column.style.background = "orange";
        }
        row.append(column);
      }
      mainGrid.append(row);
    }
  }
  
  function isSafe(matrix, row, col, val) {
    for (let i = 0; i < 9; i++) {
      if (matrix[row][i] == val || matrix[i][col] == val) {
        return false;
      }
    }
  
    let sCol = Math.floor(col / 3) * 3;
    let sRow = Math.floor(row / 3) * 3;
    for (let i = 0; i < 3; i++) {
      for (let j = 0; j < 3; j++) {
        if (matrix[i + sRow][j + sCol] == val) {
          return false;
        }
      }
    }
    return true;
  }
  
  async function solveSudoku(matrix, row = 0, col = 0) {
    if (resetState) {
      resetState = false;
      return "reset";
    }
    if (col >= 9) {
      col = 0;
      row++;
    }
  
    if (row >= matrix.length) {
      return true;
    }
    if (matrix[row][col] !== 0) {
      let val = matrix[row][col];
      matrix[row][col] =0;
      if (isSafe(matrix, row, col, val)) {
        matrix[row][col] =val;
        return solveSudoku(matrix, row, col + 1);
      } 
      matrix[row][col] = val;
      return false;
    }
  
    for (let i = 1; i <= 9; i++) {
      await updateDom(`${row}${col}`, i);
      if (isSafe(matrix, row, col, i)) {
        matrix[row][col] = i;
  
        let d = 500000;
        let result = await solveSudoku(matrix, row, col + 1);
        if (result) {
          return result;
        }
        matrix[row][col] = 0;
  
        await updateDom(`${row}${col}`, "");
      }
    }
    await updateDom(`${row}${col}`, "");
    return false;
  }
  
  function updateDom(id, val) {
    return new Promise((resolve) => {
          if (!runningState){
            resolve()
          }
        setTimeout(() => {
          document.getElementById(id).innerText = val;
          resolve();
        }, delay);
    });
  }
  
  updateInputGrid();