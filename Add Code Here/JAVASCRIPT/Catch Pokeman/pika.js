const holes = document.querySelectorAll('.hole');
const scoreBoard = document.querySelector(".score");
const countdownBorad = document.querySelector(".countdown");
const moles = document.querySelectorAll(".mole");
const start = document.querySelector('.start');

let score = 0;
let lasthole;
let timeup = false;
let countdown;
let timelimit = 20000;

function pickRandomHole(holes) {
    const randomHole = Math.floor(Math.random() * holes.length);


    const hole = holes[randomHole];

    if (hole === lasthole) {
        return pickRandomHole(holes);
    }

    lasthole = hole;
    return hole;
}


function pickup() {
    const time = Math.random() * 1300 + 400;
    const hole = pickRandomHole(holes);
    hole.classList.add("up");
    setTimeout(() => {
        hole.classList.remove("up")
        if (!timeup) pickup();
    }, time)
}

// pickup();

function startGame() {
    countdown = timelimit / 1000;
    scoreBoard.textContent = 0;
    scoreBoard.style.display = "block";

    timeup = false;
    score = 0;
    pickup()
    setTimeout(() => {
            timeup = true;
        },
        timelimit
    )
    let startcountdown = setInterval(() => {
        countdown -= 1;
        countdownBorad.textContent = countdown;

        if (countdown < 0) {
            clearInterval(startcountdown);
            countdownBorad.textContent = "Times Up!!"
        }

    }, 1000);;
}


start.addEventListener("click", startGame);


function pika() {
    score += 1;
    scoreBoard.textContent = score;
    this.style.backgroundImage = 'url("sad.png")';
    this.style.pointerEvents = "none";
    setTimeout(() => {
        this.style.backgroundImage = 'url("pika.png")';
        this.style.pointerEvents = "all";

    }, 800);
}

moles.forEach(e => e.addEventListener('click', pika));