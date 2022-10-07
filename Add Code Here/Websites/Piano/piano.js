document.addEventListener("DOMContentLoaded",main);
var on = false,screen,screenContent,info,battery,btryPercent,isTouchDevice;
isTouchDevice = ( 'ontouchstart' in window ) || ( navigator.maxTouchPoints > 0 ) || ( navigator.msMaxTouchPoints > 0 );
const synth = new Tone.Synth().toDestination();
function main(){
    document.getElementById("power").addEventListener("input",(e) => {
        on = e.target.checked;
        power();
    });
    setBattery();
    screen = id("screen");
    screenContent = id("screen-content");
    info = id("info");
    battery = $(".battery>div");
    btryPercent = id("btry-percent");
}
function power(){
    if(!on){
        //turn off
        turnOff();
    }
    else{
        //turn on
        print("Piano is Ready to Use.",2,()=>{},true);
        turnOn();
    }
}
function print(n,t,f,w){
    if(on){
    if(t===0 || t){
    if(w) {info.innerHTML="Please Wait...";}
    if(t !==0){
        setTimeout(() => {
            var l = n.length;
                info.innerHTML = n;
                f();
        },t * 1000);
        }
        else{
            info.innerHTML = n;
                f();
        }
    }else{
        info.innerHTML = "Please wait..."
        setTimeout(() => {
            var l = n.length;
            setTimeout(() => {
                info.innerHTML = n;
                f();
            },l*100);
        },100);
    }
    }
}
function setBattery(){
    let btChange = bt =>{
        bt.addEventListener('levelchange',e => {
            let lvl = Math.round(e.target.level * 100);
            btryPercent.textContent=`${lvl}%`;
            battery.style.width= lvl + "%";
        });
        let lvl = Math.round(bt.level * 100);
        btryPercent.textContent=`${lvl}%`;
        battery.style.width= lvl + "%";
    };
    if(window.navigator && window.navigator.getBattery){
    navigator.getBattery()
    .then(btChange);
    }
    else{
        btryPercent.textContent=`100%`;
        battery.style.width= "100%";
    }
}
function turnOn(){
    var Keys = document.querySelectorAll(".key");
    Keys.forEach( el => {
        if(isTouchDevice){
            el.addEventListener("touchstart",play);
            el.addEventListener("touchend",stop);
        }
        else{
            el.addEventListener("mousedown",play);
            el.addEventListener("mouseup",stop);
        }
    });
    document.documentElement.style.cssText =
        `   --screen:lightblue;
            --color:#313131;
        `;
        screenContent.style.opacity=1;
}
function turnOff(){
    var Keys = document.querySelectorAll(".key");
    Keys.forEach( el => {
        if(isTouchDevice){
            el.removeEventListener("touchstart",play);
            el.removeEventListener("touchend",stop);
        }
        else{
            el.removeEventListener("mouseup",stop);
            el.removeEventListener("mousedown",play);
        }
    });
    document.documentElement.style.cssText =
        `   --screen:#818181;
            --color:#313131;
        `;
        screenContent.style.opacity=0;
}
function play(e){
    try{
        synth.triggerAttack(e.target.dataset.n);
        var note = e.target.dataset.n;
        print(`
        <div style="width:100%;height:100%;display:flex;align-items:center;justify-content:center;font-size:2.5rem;">${note}</div>`,0,()=>{},false);
        }
        catch{}
}
function stop(e){
    try{
        synth.triggerRelease();
        }
        catch{}
}
/*MY DOM FUNCTIONS*/
function id(el){ return document.getElementById(el); }
function clas(e,i){
if(i){return document.getElementsByClassName(e)[i];}
else{return document.getElementsByClassName(e)}}
function A(query){return document.querySelectorAll(query);}
function $(query){return document.querySelector(query);}
/*________________________________*/

alert("Turn on by Tapping the power button and enjoy!")


