
// Looking for the clicks on the website

for (var i = 0; i < document.querySelectorAll(".drum").length; i++) {
    document.querySelectorAll(".drum")[i].addEventListener("click", function () {
        var char = this.innerHTML;
        makeSound(char);
        addAnimation(char);
    });
}


// Looking for the keyboard strokes
document.addEventListener("keydown", function (event) {
    makeSound(event.key);
    addAnimation(event.key);
})

function makeSound(key) {
    switch (key) {
        case 'w':
            var audio = new Audio("sounds/tom-1.mp3");
            audio.play();
            break;

        case 'a':
            var audio = new Audio("sounds/tom-2.mp3");
            audio.play();
            break;

        case 's':
            var audio = new Audio("sounds/tom-3.mp3");
            audio.play();
            break;
        case 'd':
            var audio = new Audio("sounds/tom-4.mp3");
            audio.play();
            break;

        case 'j':
            var audio = new Audio("sounds/kick-bass.mp3");
            audio.play();
            break;

        case 'k':
            var audio = new Audio("sounds/crash.mp3");
            audio.play();
            break;

        case 'l':
            var audio = new Audio("sounds/snare.mp3");
            audio.play();
            break;

        default:
            break;
    }
}

function addAnimation(charKey) {
    var char = document.querySelector("." + charKey)
    char.classList.add("pressed");
    setTimeout(function () {
        char.classList.remove("pressed");
    }, 100);
}