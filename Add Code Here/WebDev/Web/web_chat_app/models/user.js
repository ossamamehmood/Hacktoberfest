const mongoose = require('mongoose');

const userSchema = mongoose.Schema({
    username: {
        type: String, 
        required: [true, "Username cant be blank."],
        unique: [true, "That username already used"]
    },
    channel: {
        type: String,
        required: [true, "Channel name cant be blank"]
    },
    id: {
        type: String,
        required: true
    }
});


const User = mongoose.model("Users", userSchema);

module.exports = User;