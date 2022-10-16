
let currentColor = "";
let alpha ;
let tostMsg ;

window.onload = () => {
    setColor("#FFFFFF");
    tostMsg = document.querySelector(".tost");
    tostMsg.remove();
}

function setColorMode(index){

    let colorModeSelector = document.querySelector(".color-mode");
    colorModeSelector.setAttribute("data-index",index);
    let color = w3color(io.value);
    index = parseInt(index) + (alpha?3:0);

    switch(index){
        case 0 : 
            color = color.toRgbString();
            break;
        case 1 : 
            color = color.toHexString().toUpperCase();
            break;
        case 2 : 
            color = color.toHslString();
            break;
        case 3 : 
            color = color.toRgbaString();
            break;
        case 4 : 
            color = (color.toHexString() + toHex(color.opacity)).toUpperCase();
            break;
        case 5 : 
            color = color.toHslaString();
            break;
    }
    
    setColor(color);
}

function pickColor(){
    let colorPicker = document.createElement("input");
    colorPicker.type = "color";
    colorPicker.value = currentColor ;
    colorPicker.click();
    
    colorPicker.addEventListener("input",()=>{
        setColorMode(1);
        setColor(colorPicker.value);
    });
}

function setColor(color){
    let colorPreview = document.querySelector(".color-preview");
    colorPreview.style.backgroundColor = color ;
    
    io.value = color ;
    currentColor = color;
}

function toggleAlpha(){
    let modes = document.querySelectorAll(".mode");
    let a = alpha?"A":"" ;
    modes[0].innerText = "RGB" + a ;
    modes[1].innerText = "HEX" + a ;
    modes[2].innerText = "HSL" + a ;
}

function toggle(elm){
    if(elm.getAttribute("data-checked")==="true"){
        elm.setAttribute("data-checked","false");
        alpha = false;
    }else{
        elm.setAttribute("data-checked","true");
        alpha = true;
    }
    toggleAlpha();
}

function toHex(n) {
    n = n*255;
    var hex = n.toString(16);
    while (hex.length < 2) {hex = "0" + hex; }
    return hex;
}

function copyToClipboard(){
    io.select();
    io.setSelectionRange(0, 99999);
    document.execCommand("copy");
    io.blur();
    tost();
}

function tost(){
    document.body.append(tostMsg);
}
