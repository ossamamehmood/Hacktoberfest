// First pop-up and Adding "No Items in the todo list" text after pressing first popup Close button
var button = document.getElementById("button");
var popup = document.getElementById("popup");
var close = document.getElementById("close1");

button.addEventListener("click", () => {
    popup.classList.toggle("active");
})

close.addEventListener("click", () => {
    popup.classList.remove("active");
    document.getElementById("p").style.display = "block";
})

// Second pop-up
var btn = document.getElementById("button1");
var pu = document.getElementById("popup1");
var cls = document.getElementById("close2");

btn.addEventListener("click", () => {
    pu.classList.add("active");
})

cls.addEventListener("click", () => {
    pu.classList.remove("active");
})

// Deleting cards and adding "No Items in the todo list" text 
var headernewx = document.getElementById("header");
var card = document.getElementById("todo1");

function mF() {
    card.remove();
    document.getElementById("p").style.display = "block";
    headernewx.classList.remove("active");
}

// Adding head to the card
var messages = document.getElementById("head");
var textbox = document.getElementById("fp");
var button = document.getElementById("add");

button.addEventListener("click", function(){
    var newMessage = document.createElement("h2");
    newMessage.innerHTML = textbox.value;
    messages.appendChild(newMessage);
    textbox.value = "";
});

//Pressing the popup1 Add icon to add card
var addcard = document.getElementById("add");
var todoadd = document.getElementById("todo1");

addcard.addEventListener("click", () => {
    todo1.classList.add("active");
})

//Mark done strike through
function sub() {
    document.getElementById("strikethrough").style.color = "red";
    document.getElementById("strikethrough").style.textDecoration = "line-through";
    document.getElementById("strikethrough").style.fontSize = "medium";
    document.getElementById("cardbody2").style.display = "none";
}

// Adding Mark Done with first popup
document.getElementById("add2").addEventListener("click", myFunction);


function myFunction() {
    document.getElementById("cardbody2").innerHTML = "<button onclick='sub()' style='background-color: #0082F0; color: white; border: none; border-radius: 10px; cursor: pointer;'>Mark Done</button>";
}

//Pressing the popup2 add icon to add body to the card
var bodycard = document.getElementById("cardbody");
var textbox1 = document.getElementById("fp1");
var popup2add = document.getElementById("add2");

popup2add.addEventListener("click", function(){
    var newMessage2 = document.createElement("h4");
    newMessage2.innerHTML = textbox1.value;
    bodycard.appendChild(newMessage2);
    textbox1.value = "";
});

// Close/Disappear first popup automatically after hitting the Add button 
var blurgone = document.getElementById("add");
var blurheader = document.getElementById("header"); 
var blurheaderclose = document.getElementById("close1");

blurgone.addEventListener("click", () => {
    blurheader.classList.remove("active");
})

blurheaderclose.addEventListener("click", () => {
    blurheader.classList.remove("active");
})

function firstpopup() {
    document.getElementById("popup").style.display = "none";
}

// Close/Disappear Second popup automatically after hitting the Add button 
function secondpopup() {
    document.getElementById("popup1").style.display = "none";
}

// Removing "No Items in the todo list" text and adding the card 
var header = document.getElementById("header");
var buttonheader = document.getElementById("button");

buttonheader.addEventListener("click", () => {
    header.classList.toggle("active");
})

function toppopup() {
    document.getElementById("p").style.display = "none";
}

// Second popup blur background 
var headernew = document.getElementById("header");
var buttonheadernew = document.getElementById("button1");
var cardnew = document.getElementById("todo1"); 

buttonheadernew.addEventListener("click", () => {
    headernew.classList.toggle("active");
    cardnew.classList.toggle("act");
})
    
// Removing card blur through second popup Add button also with Close button and remove the blur for the head
var popup2addnew = document.getElementById("add2");
var cardnewnew = document.getElementById("todo1"); 
var headerxnew = document.getElementById("header");
var clsnew = document.getElementById("close2");

popup2addnew.addEventListener("click", () => {
    cardnewnew.classList.remove("act");
    headerxnew.classList.remove("active");
})

clsnew.addEventListener("click", () => {
    cardnewnew.classList.remove("act");
    headerxnew.classList.remove("active");
})

// Adding multiple cards
// function newElementone() {
//     var section = document.createElement("section");
//     var inputValue = document.getElementById("fp").value;
//     var t = document.createTextNode(inputValue);
//     section.appendChild(t);
//     if (inputValue === '') {
//       alert("You must write something!");
//     } else {
//       document.getElementById("todo2").appendChild(li);
//     }
//     document.getElementById("fp").value = "";
  
//     var span = document.createElement("SPAN");
//     var txt = document.createTextNode("\u00D7");
//     span.className = "close";
//     span.appendChild(txt);
//     li.appendChild(span);
  
//     for (i = 0; i < close.length; i++) {
//       close[i].onclick = function() {
//         var div = this.parentElement;
//         div.style.display = "none";
//       }
//     }
// }

