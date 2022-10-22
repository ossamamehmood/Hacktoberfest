const express = require("express");
const path = require("path");
const port = process.env.PORT || 3000;
const http = require("http");
const socketio = require("socket.io");
const { getMessage } = require("./utils/message");
const {
  addUser,
  getUser,
  removeUser,
  getUserListInChannel,
} = require("./utils/users");
require("./db/mongoose");

const app = express();
const server = http.createServer(app);
const io = socketio(server);

const publicPathDirectory = path.join(__dirname, "../public");
app.use(express.static(publicPathDirectory));

io.on("connection", (socket) => {
  socket.on("join", ({ username, channel }, callback) => {
    const { user, error } = setTimeout(
      addUser,
      1000,
      username,
      channel,
      socket.id
    );
    //const { user, error } = addUser(username, channel, socket.id);
    if (error) {
      return callback(error);
    }
    setTimeout(() => {
      getUserListInChannel(channel, (err, users) => {
        socket.join(channel);
        io.to(channel).emit("sidebarInfo", {
          channel,
          users: users,
        });
      });
    }, 2000);

    socket.emit("recievedMessage", getMessage("SYSTEM:", `WELCOME ${username}`));
    socket.broadcast
      .to(channel)
      .emit(
        "recievedMessage",
        getMessage("SYSTEM:", `${username} is Connected`)
      );
  });

  socket.on("sendMessage", (text, callback) => {
    getUser(socket.id, (err, user) => {
      if (text === "HELLO") return callback(false);
      io.to(user.channel).emit(
        "recievedMessage",
        getMessage(user.username, text)
      );
      callback(true);
    });
  });

  socket.on("sendLocation", ({ latitude, longitude }) => {
    getUser(socket.id, (err, user) => {
      const { username, channel } = user;
      const url = `http://maps.google.com?q=${latitude},${longitude}`;
      io.to(channel).emit(
        "recievedMessage",
        getMessage(username, undefined, url)
      );
    });
  });

  socket.on("disconnect", () => {
    //console.log("disconnected");
    removeUser(socket.id, (error, user) => {
      //console.log(user);
      if (user) {
        const { username, channel } = user;

        getUserListInChannel(channel, (err, users) => {
          io.to(channel).emit("sidebarInfo", {
            channel,
            users: users,
          });
        }),
          io
            .to(channel)
            .emit("recievedMessage", getMessage("SYSTEM:", `${username} LEFT`));
      }
    });
  });
});

server.listen(port, () => {
  console.log(`http://localhost:${port}`);
});

/*
//////GENEL OLARAK//////////
io.emit = tüm bağlı socketlere yollar 
socket.emit = belli sockettekki kişilere mesajı yollar (bağlandığımız socketten bize hoşgeldiniz yazması)
socket.broadcast.emit = bu socket haricindeki herkese gönder (user left, user joined  gibi)

/////KANALLAR İŞİN İÇİNE GİRDİĞİNDE////////
io.to.emit = kanala bağlanan kişiye mesajı gönder 
socket.broadcast.to.emit = bu socket dışındaki kişilere mesajı gönder

*/
