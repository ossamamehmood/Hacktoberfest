var timer = 60;
var score = 0;
var hitrn = 0;

function increaseScore() {
    score += 10;
    document.querySelector("#Scoreval").textContent = score;
}

function getNewHit() {
    hitrn = Math.floor(Math.random() * 10);
    document.querySelector("#hitval").textContent = hitrn;
}

function makeBubble() {
    var clutter = "";

    for (let index = 1; index <= 90; index++) {
        var rn = Math.floor(Math.random() * 10);
        clutter += `<div class="bubble">${rn}</div>`;
    }

    document.querySelector("#pbtm").innerHTML = clutter;
}

function runTimer() {
    var timerint = setInterval(function () {
        if (timer > 0) {
            timer--;
            document.querySelector("#timerval").textContent = timer;
        }
        else {
            clearInterval(timerint);
            document.querySelector("#pbtm").innerHTML = `<h1>Your score is ${score} Game Over</h1>`;
        }
    }, 1000);
}

document.querySelector("#pbtm").addEventListener("click",
    function (dets) {
        var clickNumber = Number(dets.target.textContent);
        if (clickNumber === hitrn) {
            increaseScore();
            getNewHit();
            makeBubble();
        }
    });

// increaseScore();
getNewHit();
makeBubble();
runTimer();