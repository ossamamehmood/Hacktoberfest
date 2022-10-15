// var playerName =prompt("Enter The Player Name :");
// document.querySelector("p").innerHTML=playerName;

randomChoice();

function randomChoice()
{
    var choice1=Math.floor(Math.random()*3)+1;
    var choiceName1="hand"+choice1+".png";
    var image1=document.querySelectorAll("img")[0];
    image1.setAttribute("src",choiceName1);

    var choice2=Math.floor(Math.random()*3)+1;
    var choiceName2="hand"+choice2+".png";
    var image2=document.querySelectorAll("img")[1];
    image2.setAttribute("src",choiceName2);

    if(choice1===choice2)
    {
        document.querySelector("h1").innerHTML="Match Draw..!!";
    }
    else if(choice1===1)
    {
        if(choice2===2)
        {
            document.querySelector("h1").innerHTML="Computer Won..!!";
        }
        else if(choice2===3)
        {
            document.querySelector("h1").innerHTML="You Won...Congrats!!";
        }
    }
        
    else if(choice1===2)
    {
        if(choice2===1)
        {
            document.querySelector("h1").innerHTML="Computer Won..!!";
        }
        else if(choice2===3)
        {
            document.querySelector("h1").innerHTML="You Won...Congrats!!";
        }
    }    
        
    else
        {
        if(choice2===2)
            {
            document.querySelector("h1").innerHTML="Computer Won..!!";
            }
        else
            {
            document.querySelector("h1").innerHTML="You Won...Congrats!!";
            }
        }
}
   

    

