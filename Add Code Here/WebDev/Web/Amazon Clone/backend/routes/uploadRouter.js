const multer = require("multer");
const express = require('express');
var router = express.Router();
const isAuth = require('../middleware/authUser');
const isAdmin = require('../middleware/authAdmin');
const path  = require("path");

var __dirname = path.resolve(__dirname,'../../uploads');
//const publicPathUrl = path.join(__dirname,'/uploads');

const storage = multer.diskStorage({
  destination(req, file, cb){
    cb(null, __dirname);
  },
  filename(req,file,cb){
    cb(null,`${Date.now()}.jpg`);
  }
})
const upload = multer({storage});


router.post('/', isAuth, isAdmin, upload.single('image'), (req, res)=> {
  console.log("PATH22:",`${req.file.path}`);
  res.send(`${req.file.path}`);
  
  
});


module.exports = router;

