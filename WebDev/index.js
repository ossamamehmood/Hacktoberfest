function currentTime() {
    let date=new Date();
    let hh = date.getHours();
    let mm = date.getMinutes();
    let ss = date.getSeconds();
    
    const days = ["Sunday" , "Monday" , "Tuesday" , "Wednesday" , "Thursday" , "Friday" , "Saturday"]
    const Months=["January","Febraury","March","April","May","June","July","August","September","October","November","December"]
    
    let session = "AM";
    let greeting="Good Morning!!";
    
    if(hh > 12 && hh<=16){
        session = "PM";
        greeting="Good Afternoon!!";
     }
     else if(hh>16 && hh<=19){
      session="PM";
      greeting="Good Evening!!"
  
     }
     else if(hh>19 && hh<=24 ){
        session="PM";
        greeting="Good Night!!";
     }
  
     hh = (hh < 10) ? "0" + hh : hh;
     mm = (mm < 10) ? "0" + mm : mm;
     ss = (ss < 10) ? "0" + ss : ss;
      
     let time = hh + ":" + mm + ":" + ss + " " + session;
  
     let pdate =  Months[date.getMonth()]  + " " + date.getDate() + " " + date.getFullYear() + "  " + days[date.getDay()] ; 
  
    document.getElementById("clock").innerText = time; 
    // document.getElementById("greet").innerText = greeting; 
    document.getElementById("date").innerText = pdate;
  
  
  }
  
  setInterval(currentTime,1000); //to call the fucntion every second to renew the clock 