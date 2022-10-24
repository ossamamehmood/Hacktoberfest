const express=require('express');
const path=require('path');
const bodyParser=require('body-parser');
const mongoose = require('mongoose');
mongoose.connect('mongodb://localhost/contactDance', {useNewUrlParser: true, useUnifiedTopology: true});
const app=express();
const port = 3000;

//Define mongoose schema
const ContactSchema = new mongoose.Schema({
    name: String,
    phone: String,
    email: String,
    adress: String,
    desc: String
  });

const Contact = mongoose.model('Contact', ContactSchema);


app.use('/static',express.static('static'));
app.use(express.urlencoded());

app.set('view engine','pug');
app.set('views',path.join(__dirname,'views'));


app.get('/', (req,res)=>{
    res.status(200).render('home.pug');
});

app.get('/contactUs',(req,res)=>{
    res.status(200).render('contact.pug');
});

app.post('/contactUs',(req,res)=>{
    var Data=new Contact(req.body);
    Data.save()
    .then(()=>{
        res.render('thankYou.pug')
    }).catch(()=>{
        res.status(400).send("Item was not saved")
    });

});





app.listen(port,()=>{
    console.log(`The app started running on port ${port}`);
})