const jwt = require("jsonwebtoken");

const isAuth = (req, res, next) => {
  const authorization = req.headers.authorization;

  if(authorization){
    const token = authorization.slice(7,authorization.length);
    jwt.verify(token,process.env.JWT_SECRET || 'secretJWT', (err, decode)=>{
      if(err) {
        res.status(401).send({message: 'Invalid Token'})
      }else{
        req.user = decode;
        next();
      }
    })
  
  }else {
    res.status(401).send({message: 'No Token'})
  }

}


module.exports = isAuth;