const timeDislay = document.querySelector("#timeDisplay");
const startbtn = document.querySelector("#startbtn");
const pausebtn = document.querySelector("#pausebtn");
const resetbtn = document.querySelector("#resetbtn");

let startTime = 0;
let elapsedTime = 0;
let paused = true;
let intervalID;
let hrs = 0;
let mins = 0;
let secs = 0;
let milisecs = 0;

startbtn.addEventListener("click", () => {
    if (paused) {
        paused = false;
        startTime = Date.now() - elapsedTime;
        intervalID = setInterval(updateTime, 100);
    }
});
resetbtn.addEventListener("click", () => {
    startTime = 0;
    elapsedTime = 0;
    paused = true;
    intervalID;
    hrs = 0;
    mins = 0;
    secs = 0;
    milisecs = 0;
    clearInterval(intervalID);
    timeDislay.textContent = `00:00:00:00`;
});
pausebtn.addEventListener("click", () => {
    if (!paused) {
        paused = true;
        elapsedTime = Date.now() - startTime;
        clearInterval(intervalID);
    }
});

function updateTime() {
    elapsedTime = Date.now() - startTime;
    secs = Math.floor((elapsedTime / 1000) % 60);
    milisecs = Math.floor((elapsedTime) % 60);
    mins = Math.floor((elapsedTime / (1000 * 60)) % 60);
    hours = Math.floor((elapsedTime / (1000 * 60 * 60)) % 60);

    secs = pad(secs);
    mins = pad(mins);
    hours = pad(hours);
    milisecs = pad(milisecs);

    timeDislay.textContent = `${hours}:${mins}:${secs}:${milisecs}`;

    function pad(time) {
        return (("0" + time).length > 2 ? time : "0" + time);
    }
}