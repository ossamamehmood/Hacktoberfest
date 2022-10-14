
/**
 * Header HTTP
 *  
 */
const http = require("http")

const server = http.createServer((req, res) => {

    let dataHeader, 
    dataAutorization, 
    splitData,
    dataUser, 
    dataResponse;

    res.setHeader("Content-Type", "application/json");


    dataHeader = req.headers;

    console.log(dataHeader);


    dataAutorization = dataHeader.authorization;


    if(!dataAutorization){
        dataResponse = {
            data: "Undefined Autorization"
        };


        return res.end(JSON.stringify(dataResponse));
    }

    splitData = dataAutorization.split(" ");

    dataUser = splitData[1];

    userPass = Buffer.from(dataUser, "base64").toString();


    dataResponse = {
        token : dataHeader.authorization,
        userPass
    };

    return res.end(JSON.stringify(dataResponse));
});

//server.listen(5500)
