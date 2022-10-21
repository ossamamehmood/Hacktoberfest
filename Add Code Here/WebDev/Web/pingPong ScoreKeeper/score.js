const p1display=document.querySelector('#player1'); // scores
const p2display=document.querySelector('#player2');

const p1button=document.querySelector('#p1button');
const p2button=document.querySelector('#p2button');
const reset=document.querySelector('#reset');
const selectWinningScore=document.querySelector('#total');

let winningScore=3; // by default
let gameOver=false;
let p1score=0;
let p2score=0;
p1button.addEventListener('click',function(){
    // when we click player 1 button our p1score increment by 1
   if(!gameOver){
       p1score+=1;
       if(p1score===winningScore){
            gameOver=true;
            p1display.classList.add('winner');
            p2display.classList.add('looser');
       }
        p1display.innerHTML=p1score;
   }
})
p2button.addEventListener('click',function(){
    // when we click player 1 button our p1score increment by 1
    if(!gameOver){
        p2score+=1;
        if(p2score===winningScore){
             gameOver=true;
             p2display.classList.add('winner');
             p1display.classList.add('looser');
        }
         p2display.innerHTML=p2score;
    }
})

selectWinningScore.addEventListener('change',function(){
    // to get the value out we use this this
    // alert(this.value);
    winningScore= parseInt(this.value);
    restart(); // we executing it here as passing as call back
})

reset.addEventListener('click',restart) // we are not executing function here its just cal by refrence

function restart(){
    gameOver=false;
    p1score=0;
    p2score=0;
    p1display.innerHTML=p1score;
    p2display.innerHTML=p2score;
    p1display.classList.remove('winner','looser');
     p2display.classList.remove('looser','winner');

};