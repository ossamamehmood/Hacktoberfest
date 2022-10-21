const buttonColor = ["red","blue","green","yellow"]

let gamePattern = []
let userClickedPattern = []

let level = 0

let hasGameStart = false
let isGameOver = false

$(document).keypress(function(){
    if(!hasGameStart){
        console.log("entered keypress")
        nextSequence()
        hasGameStart=true
    }
})

$(document).click(function(){
    if(!hasGameStart && !isGameOver){
        console.log("entered click")
        nextSequence()
        hasGameStart=true
    }
})

function nextSequence(){

    userClickedPattern=[]

    const randomNumber = Math.floor(Math.random()*4)
    const randomChosenColour = buttonColor[randomNumber]

    gamePattern.push(randomChosenColour)

    console.log(gamePattern)

    $("#"+randomChosenColour).fadeOut(100).fadeIn(100).fadeOut(100).fadeIn(100)   

    const audio = new Audio("sounds/"+randomChosenColour+".mp3")
    audio.play()

    $("#level-title").text("Level "+level);
    level++
}

$(".btn").click(function () { 
    const userChosenColour = $(this).attr("id");
    userClickedPattern.push(userChosenColour)

    playSound(userChosenColour)
    animatePress(userChosenColour)

    checkAnswer(userClickedPattern.length-1)

});

function playSound(name){
    const audio = new Audio("sounds/"+name+".mp3")
    audio.play()
}


function animatePress(currentColour){

    $("."+currentColour).addClass("pressed")

    setTimeout(function(){
        $("."+currentColour).removeClass("pressed");
    },100)

}

function checkAnswer(currentLevel){
    if(gamePattern[currentLevel]===userClickedPattern[currentLevel]){
        console.log("success")

        if(userClickedPattern.length===gamePattern.length){
            setTimeout(function(){
                nextSequence()
            },1000)
        }
    }

    else{
        console.log("wrong")

        playSound("wrong")

        $("body").addClass("game-over");
        setTimeout(function(){
            $("body").removeClass("game-over")
        },200)


        gamePattern=[]
        hasGameStart = false 
        isGameOver = true
        level = 0

        $("#level-title").text("Game Over, Press A Key or Click to Start")

        setTimeout(function(){
            isGameOver=false
        },1000)
 
    }
}

