const express=require("express");
const bodyParser=require("body-parser");


const app=express();
app.use(bodyParser.urlencoded({extended: true}));

app.get("/", function(request, respond){
    respond.sendFile(__dirname+"/calculator.html");
    

});

app.post("/", function(request, respond){
    respond.send("Answer:");
    console.log(request.body);
    
    
});



app.use(express.static(__dirname + '/public'));

app.listen(3000, function(){
    console.log("Server started at port 3000")
});