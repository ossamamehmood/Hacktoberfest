const deg =6;
const hr = document.querySelector(".hr");
const min = document.querySelector(".min");
const sec = document.querySelector(".sec");

function update_clock(){
    let day= new Date();
    console.log(day);
    let hour = day.getHours() *30;  //angle 1hr=30deg
    let minute = day.getMinutes() *6;  //angle 1min=6deg
    let second = day.getSeconds() *6;  //angle 1sec=6deg
    
    hr.style.transform = `rotatez(${hour+(minute/12)}deg)`;   // 30*12=360
    min.style.transform = `rotatez(${minute+(second/60)}deg)`;  //6*60=360
    sec.style.transform = `rotatez(${second}deg)`;
}

setInterval(update_clock,1000);

// let week_day= day.getDay();
// console.log(week_day);
