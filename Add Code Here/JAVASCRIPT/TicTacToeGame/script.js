const X_PLAYER = 'x'
const O_PLAYER = 'circle'
const POSSIBLE_WINS = [
  [0, 1, 2],
  [3, 4, 5],
  [6, 7, 8],
  [0, 3, 6],
  [1, 4, 7],
  [2, 5, 8],
  [0, 4, 8],
  [2, 4, 6]
]

const cellContent = document.querySelectorAll('[data-cell]')
const boardFeature = document.getElementById('gameBoard')
const winResult = document.getElementById('win-alert')
const replay = document.getElementById('restartGame')
const winAlert = document.getElementById('win-alert-text')

let playerTwo = false

beginGame()

function beginGame() {

  playerTwo = false

  cellContent.forEach(cell => {
    cell.classList.remove(X_PLAYER)
    cell.classList.remove(O_PLAYER)
    cell.removeEventListener('click', handleCellClick)
    cell.addEventListener('click', handleCellClick, { once: true })
  })

  setBoardHoverClass()
  winResult.classList.remove('show')
}

function handleCellClick(evt) {
  const cell = evt.target
  const activeClass = playerTwo ? O_PLAYER : X_PLAYER
  placeMark(cell, activeClass)
  if (gameCheck(activeClass)) {
    completeGame(false)
  } else if (drawn()) {
    completeGame(true)
  } else {
    changeTurn()
    setBoardHoverClass()
  }
}

function completeGame(draw) {
  if (draw) {
    winResult.innerText = 'No Winner. Tied!'
  } else {
    winResult.innerText = `Player with ${playerTwo ? "O's" : "X's"} has won!`
  }
  winResult.classList.add('show')
}

function drawn() {
  return [...cellContent].every(cell => {
    return cell.classList.contains(X_PLAYER) || cell.classList.contains(O_PLAYER)
  })
}

function placeMark(cell, activeClass) {
  cell.classList.add(activeClass)
}

function changeTurn() {
  playerTwo = !playerTwo
}

function setBoardHoverClass() {
  boardFeature.classList.remove(X_PLAYER)
  boardFeature.classList.remove(O_PLAYER)

  if (playerTwo) {
    boardFeature.classList.add(O_PLAYER)
  } else {
    boardFeature.classList.add(X_PLAYER)
  }
}

function gameCheck(activeClass) {
  return POSSIBLE_WINS.some(combination => {
    return combination.every(index => {
      return cellContent[index].classList.contains(activeClass)
    })
  })
}