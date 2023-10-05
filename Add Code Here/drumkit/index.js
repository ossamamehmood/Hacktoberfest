numberOfDrums=document.querySelectorAll(".drum").length
for(i=0;i<numberOfDrums;i++){

    document.querySelectorAll(".drum")[i].addEventListener("click",function (){
        var buttonInnerHTML=this.innerHTML
        makeSound(buttonInnerHTML)
        
    })
}

document.addEventListener("keypress",function(event){
    makeSound(event.key)
})

function makeSound(key){
    switch (key) {
        case "w":
            var audio = new Audio("sounds/Floor-Tom-Drum-Hit-Level-7B-www.fesliyanstudios.com.mp3")
            audio.play()
            
            break;

        case "a":
            var audio = new Audio("sounds/Medium-Tom-Drum-Hit-Level-7B-www.fesliyanstudios.com.mp3")
            audio.play()

            break
        case "s":
            var audio = new Audio("sounds/Small-Tom-Drum-Hit-Level-6A-www.fesliyanstudios.com.mp3")
            audio.play()

            break
        case "d":
            var audio = new Audio("sounds/Bass-Drum-Hit-Level-6c-www.fesliyanstudios.com.mp3")
            audio.play()
    
            break
        case "j":
            var audio = new Audio("sounds/Snare-Drum-Hit-Level-6b-www.fesliyanstudios.com.mp3")
            audio.play()
        
            break
        case "k":
            var audio = new Audio("sounds/crash-cymbal-hit-140577.mp3")
            audio.play()
            
            break
        case "l":
            var audio = new Audio("sounds/Trash-China-Cymbal-Crescendo-Wash-www.fesliyanstudios.com.mp3")
            audio.play()
                
            break

    
        default:alert("Click the right button or i send you to jesus!!!!")
            break;
    }

}
