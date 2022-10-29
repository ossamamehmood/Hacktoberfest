require('dotenv').config();
const express = require("express");
const bodyParser = require("body-parser");
const ejs = require("ejs");
const mongoose = require('mongoose');
const encrypt = require('mongoose-encryption');

const app = express();
app.set('view engine', 'ejs');
app.use(bodyParser.urlencoded({
    extended: true
}));
app.use(express.static("public"));
mongoose.connect("mongodb://localhost:27017/userDB")
const userSchema = new mongoose.Schema({
    email: String,
    password: String
})
userSchema.plugin(encrypt, { secret: process.env.ENCRYPTKEY, encryptedFields: ['password'] });
const User = mongoose.model("User", userSchema);

//TODO
app.get("/", function (req, res) {
    res.render('home')
});
app.get("/login", function (req, res) {
    res.render('login')
});
app.get("/register", function (req, res) {
    res.render('register')
});

app.post("/register", function (req, res) {
    const newUser = new User({
        email: req.body.username,
        password: req.body.password
    });
    newUser.save(function (err) {
        if (!err) {
            res.render("secrets");
        } else {
            res.send(err)
        }
    });
});
app.post("/login", function (req, res) {
    User.find({ email: req.body.username }, function (err, foundUser) {
        if (!err && foundUser) {
            res.render('secrets')
        } else {
            res.send("user not found  " + err)
        }
    })
});


app.listen(3000, function () {
    console.log("Server started on port 3000");
});