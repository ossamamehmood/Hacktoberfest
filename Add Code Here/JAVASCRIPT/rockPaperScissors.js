let playGame=confirm("Shall We Play rock,paper and scissors ?");
if(playGame){
         //play
         let PlayerChoice = prompt("Please enter rock, paper and scissors")
         if(PlayerChoice){
            let PlayerOne=PlayerChoice.trim().toLowerCase();
            if(PlayerOne == "rock" || PlayerOne == "paper" || PlayerOne == "scissors"){
                let ComputerChoice=Math.floor(Math.random()*+1);
                let computer= ComputerChoice === 1 ? "Rock"
                : ComputerChoice === 2 ? "Paper" 
                : "scissors";
            let result = (PlayerOne === computer) ? "Tie Game": (PlayerOne === ("rock" && computer === "paper") ? (`playerone : ${PlayerOne} \n Computer : ${computer}\nComputer Wins !`): (PlayerOne === "paper" && computer === "scissors" )? (`playerone : ${PlayerOne} \n Computer : ${computer}\nComputer Wins !`): (PlayerOne === "scissors" && computer === "rock") ? (`playerone : ${PlayerOne} \n Computer : ${computer}\nComputer Wins !`)? `playerone : ${PlayerOne} \n Computer : ${computer}\n Player one Wins !`));
            alert(result);
            }
            else{
                alert("You didn't enter rock, papers or scissors.")
            }
         }
         else{
            alert("Guess you changed your mind Maybe next time");
         }
}       
else{
    alert("Ok, maybe next time !" );
}