const mongoose = require('mongoose');

const connectionUrl = "mongodb://localhost:27017/chat-app";
console.log('DB CONNECTED');
mongoose.connect(connectionUrl, {useNewUrlParser: true, useCreateIndex: true, useUnifiedTopology: true});

