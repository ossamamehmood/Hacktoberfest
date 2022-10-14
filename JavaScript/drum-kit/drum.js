var drumNo=document.querySelectorAll("button").length;

//for (var i=0;i<drumNo;i++){

    document.querySelectorAll("button")[0].addEventListener("click",function(){
        var audio=new Audio("tom-1.mp3");
        audio.play();
    })
    document.querySelectorAll("button")[1].addEventListener("click",function(){
        var audio=new Audio("tom-2.mp3");
        audio.play();
    })
    document.querySelectorAll("button")[2].addEventListener("click",function(){
        var audio=new Audio("tom-3.mp3");
        audio.play();
    })
    document.querySelectorAll("button")[3].addEventListener("click",function(){
        var audio=new Audio("tom-4.mp3");
        audio.play();
    })
    document.querySelectorAll("button")[4].addEventListener("click",function(){
        var audio=new Audio("snare.mp3");
        audio.play();
    })
    document.querySelectorAll("button")[5].addEventListener("click",function(){
        var audio=new Audio("crash.mp3");
        audio.play();
    })
    document.querySelectorAll("button")[6].addEventListener("click",function(){
        var audio=new Audio("kick-bass.mp3");
        audio.play();
    })
