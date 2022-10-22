let jokes=[
    " I was wondering why the frisbee kept getting bigger and bigger, but then it hit me.","When life gives you melons, you might be dyslexic.","Don’t you hate it when someone answers their own questions? I do." , "The problem with kleptomaniacs is that they always take things literally."," I used to think I was indecisive. But now I’m not so sure."," I failed math so many times at school, I can’t even count.","A termite walks into the bar and asks, ‘Is the bar tender here?’","wo fish are in a tank. One says, ‘How do you drive this thing?’"
];
  
  let jokeText=document.getElementById("joke");
  let clicks=0;
  
  function updateJoke(){
    
    clicks=clicks+1;
    clicks=clicks%8;
    //the array just cycles to give new jokes
    jokeText.textContent=jokes[clicks];
    
  }

