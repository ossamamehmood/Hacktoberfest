var randomNumber1=Math.floor(Math.random()*6)+1;
var randomDiceImage1= "dice"+randomNumber1+".png";
var image1=document.querySelectorAll("img")[0];
image1.setAttribute("src",randomDiceImage1);

var randomNumber2=Math.floor(Math.random()*6)+1;
var randomDiceImage2= "dice"+randomNumber2+".png";
var image2=document.querySelectorAll("img")[1];
image2.setAttribute("src",randomDiceImage2);

if(randomNumber1>randomNumber2){
    document.querySelector("h1").innerHTML="🚩 Player 1 Wins!";
}
if(randomNumber2>randomNumber1){
    document.querySelector("h1").innerHTML="🚩 Player 2 Wins! ";
}
if(randomNumber1==randomNumber2){
    document.querySelector("h1").innerHTML="Draw";
}
