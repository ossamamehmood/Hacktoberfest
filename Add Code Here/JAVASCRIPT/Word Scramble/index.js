let words=
[
    {
        jumbled:"diwoswn",
        correct:"windows"
    },
    {
        jumbled:"mputcoer",
        correct:"computer"
    },
    {
        jumbled:"dnodrai",
        correct:"android"
    },
    {
        jumbled:"beaydkor",
        correct:"keyboard"
    },
    {
        jumbled:"arphenoe",
        correct:"earphone"
    },
    {
        jumbled:"seuom",
        correct:"mouse"
    },
    {
        jumbled:"latbet",
        correct:"tablet"
    },
    {
        jumbled:"podaucth",
        correct:"touchpad"
    },
    {
        jumbled:"oremym",
        correct:"memory"
    },
       {
        jumbled:"sicrmofot",
        correct:"microsoft"
    }

]

let currentWord=0;
let score=0;

document.querySelector("#inp").value="";

function displayWord()
{
    document.querySelector("#jumword").innerText = 
    words[currentWord].jumbled;

    document.querySelector("#score").innerText=score;
}


displayWord();


function checkAnswer()
{
    
            let answer=document.querySelector("#inp").value;

            if(answer.toLowerCase()===words[currentWord].correct.toLowerCase()){

                score++;

            }

            if(currentWord==words.length-1){

                let msg="";

                if(score===3){
                    msg="Amazing game "+score;
                }
                else if(score===2){
                    msg="Good Game "+score
                }
                else if(score<1){
                    msg="Good Try "+score
                }

                sessionStorage.setItem("totalScore", score);
                window.location.href ="http://127.0.0.1:5500/Day%203%20Game/congrats.html";
            }
            else{
                currentWord++;
                displayWord();
                document.querySelector("#inp").value="";
            }

            

    
}















