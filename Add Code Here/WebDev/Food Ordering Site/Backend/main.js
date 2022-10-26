const http=require('http');
const fs=require('fs');

const hostname='127.0.0.1';
const port=3000;

const home=fs.readFileSync('../Index.html');
const orders=fs.readFileSync('../orders.html');
const contactUs=fs.readFileSync('../contactUs.html');

const server =  http.createServer((req,res)=>{
        let url=req.url;
        res.status=200;
        res.setHeader('Content-type','text/html');
        if(url=='/'){
            res.end(home);
        }
        else if(url=='orders.html'){
            res.end(orders);
        }
        else if(url=='contactUs.html'){
            res.end(contactUs);
        }
});


server.listen(port,hostname,()=>{
    console.log(`Server listning to //${port} on ${hostname}`);
})