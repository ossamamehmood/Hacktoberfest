//function for send icon color change.
function checkMessage(){
    if(document.getElementById("Message").value !== ""){
        document.getElementById("send").style.color = "rgb(144, 164, 174)";
    }
    else{
        document.getElementById("send").style.color = "rgb(82, 90, 94)";
    }
}

//function for insert icon.
function insert(x){
    document.getElementById("PlusAdd").style.transform = "scale(" + x + ")";
}

//------
window.onload = function(){
    document.getElementById("userName").innerText=bot.name
    document.getElementById("settingsUserName").innerText=bot.name
    document.getElementById("set1").innerText=" Create Group with " + bot.name;
    document.getElementById("Message").addEventListener("input", checkMessage);
    document.getElementById("plus").addEventListener("click", function(){
        insert(1);
    })
    document.getElementById("messageBackground").addEventListener("click", function(){
        insert(0);
    })
    document.getElementById("send").addEventListener("click", sendMessage);

    /*document.getElementById("Message").addEventListener("change", sendMessage);*/
   document.getElementById("send").style.color = "rgb(82, 90, 94)";
   document.getElementById("settings").style.display="none";
   document.getElementById("settingsBack").addEventListener("click", openOrCloseSettings);
   document.getElementById("Settings").addEventListener("click", openOrCloseSettings)
}

//-------

var bot = {
    name:"Shinchan Nohara",
    image:"D:\Web Development\Chat app\shinchan.jpg",
    message:["Hmm...", "I've seen your profile. You have a lot of followers. wow", "I am just a bot, I don't really know what are you saying.", "I saw some of your codes. You are an awesome programmer.", "Hey", " Idk what are you talking about", "What do you think", " How are you?", "The weather is so good.", " Nice profile photo.", "Wanna be friends?", "..."]
}

//reply
function receiveMessage(){
    setTimeout(function(){
        var messageBar = document.createElement("div");
        messageBar.className = "messageContainer"
        var newMessage = document.createElement("div");
        document.getElementById("messageBackground").appendChild(messageBar);
        messageBar.appendChild(newMessage)
        newMessage.className = "received";
        newMessage.innerText = bot.message[Math.floor(Math.random() * bot.message.length)];
        var photo = document.createElement("img");
        photo.className = "Image";
        photo.src = bot.image
        messageBar.appendChild(photo);
    }, 1500);
}

//send message
function sendMessage(){
    if(document.getElementById("send").style.color !== "rgb(82, 90, 94)"){
        setTimeout(function(){
        var messageBar = document.createElement("div");
        messageBar.className = "messageContainer";
        var newMessage = document.createElement("div");
        document.getElementById("messageBackground").appendChild(messageBar);
        messageBar.appendChild(newMessage);
        newMessage.className = "sent";
        newMessage.innerText = document.getElementById("Message").value;
        document.getElementById("Message").value=""
        checkMessage()
        }, 150);
        receiveMessage();
    }
}

function block(){
    alert("Oh no :'(")
}

function openOrCloseSettings(){
    if(document.getElementById("settings").style.display=="block"){
        document.getElementById("settings").style.display="none"
    }
    else{
        document.getElementById("settings").style.display="block"
    }
}

