// javasript embaded on the end of html
// so it will slow image manupulation so so this in css
//
// document.querySelectorAll("button").forEach(element => {
//     element.style.backgroundImage = "url('images/" + element.classList[2] + ".png')";
// });
// 
document.querySelectorAll(".drum").forEach(element => {
    element.addEventListener("click", function () {
        makeSound(element);
        runAnimation(element);
        // var audio = new Audio("sounds/" + element.classList[2] + ".mp3");
        // audio.play();
    });
});

// document.querySelector(".tom1")
document.addEventListener("keypress", function (event) {
    makeSound(document.querySelector("." + event.key));
    runAnimation(document.querySelector("." + event.key));
    // var audio = new Audio("sounds/" + document.querySelector("." + event.key).classList[2] + ".mp3");
    // audio.play();
    //
    // var keyName = event.key;
    // var drumType = document.querySelector("." + keyName).classList[2];
    // var audio = new Audio("sounds/" + drumType + ".mp3");
    // audio.play();
});

function makeSound(element) {
    var audio = new Audio("sounds/" + element.classList[2] + ".mp3");
    audio.play();
}
function runAnimation(element) {
    element.classList.add("pressed");
    setTimeout(function () {
        element.classList.remove("pressed");
    }, 100);
}
