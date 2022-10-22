const socket = io();

const sendLocationButton = document.querySelector("#sendLocation");
const sendMessageButton = document.querySelector("#send");
const messageInput = document.querySelector('#message')

const receivedMessage = document.querySelector('#receivedMessage')
const sidebarInfo = document.querySelector('#sidebarInfo')

const receivedMessageTemplate = document.querySelector('#receivedMessageTemplate').innerHTML;
const sidebarInfoTemplate = document.querySelector('#sidebarInfoTemplate').innerHTML;

const { username, channel } = Qs.parse(location.search, {ignoreQueryPrefix: true});



socket.emit('join', {username, channel} , (error,user) => {
    if (error){
        alert(error)
    }
});



sendMessageButton.addEventListener("click", () => {
    sendMessageButton.setAttribute("disabled", "disabled");
  const text = messageInput.value;
  socket.emit("sendMessage", text, (isDelivered) => {
    if (isDelivered) {
      console.log("Sent");
      
    } else {
      console.log("Didn't sent");
    }
    messageInput.value = '';
    messageInput.focus();
    sendMessageButton.removeAttribute('disabled');
  });
});

socket.on("recievedMessage", (messageObj) => {
    const {username, message , url,createdAt} = messageObj;
  const template = Handlebars.compile(receivedMessageTemplate);
  receivedMessage.insertAdjacentHTML('beforeend', template({
      username,
      message,
      url,
      createdAt: moment().format('HH:mm')
      
  }));
});

sendLocationButton.addEventListener('click', () => {
  
  if (!navigator.geolocation) {
    console.log('Error');
    sendLocationButton.removeAttribute('disabled');
    return;
  }
  navigator.geolocation.getCurrentPosition((position) => {
      const {latitude , longitude} = position.coords;
    socket.emit("sendLocation", {
      latitude,
      longitude
    });
    sendLocationButton.removeAttribute('disabled');

  });
});


socket.on('sidebarInfo', ({channel , users}) => {
    const template = Handlebars.compile(sidebarInfoTemplate);
    sidebarInfo.innerHTML = template({
        channel,users
    });
});