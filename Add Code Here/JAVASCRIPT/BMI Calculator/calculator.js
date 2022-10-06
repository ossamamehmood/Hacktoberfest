const express = require("express");
const bodyParser = require("body-parser");
const { urlencoded } = require("body-parser");
const app = express();

//creating route
app.get("/",function(req,res){
    res.sendFile( __dirname + "/index.html");
});

app.use(bodyParser.urlencoded({extended: true}));

app.post("/", function(req,res){
    var num1 = Number(req.body.num1);
    var num2 = Number(req.body.num2);

    var result = num1 + num2;

    res.send("The result of the calculation is " + result);
});

app.listen(3000);


app.get("/bmiCalculator",function(req,res){
   res.sendFile( __dirname + "/bmiCalculator.html");
});

app.post("/bmiCalculator",function(req,res){
    var weight = parseFloat(req.body.weight);
    var height = parseFloat(req.body.height);

    var bmi = weight/(height*height);

    res.send("Your BMI is " + bmi );
});
