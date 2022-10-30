const plusBtn = document.getElementById("plus");
const minusBtn = document.getElementById("minus");
const countDisplay = document.getElementById("countDisplay");
let count = 0;

plusBtn.addEventListener("click", () => {
    count++;
    displayCount();
});

minusBtn.addEventListener("click", () => {
    count--;
    displayCount();
});

function displayCount() {
    countDisplay.innerText = count;
}

function fetchAnAPI(){
    fetch("https:")
}