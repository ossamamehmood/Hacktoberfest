const express = require('express')
var router = express.Router();
var dotenv = require("dotenv");
dotenv.config();

router.get('/paypal', (req, res) => {
  console.log(process.env.PAYPAL_CLIENT_ID);
  res.send(process.env.PAYPAL_CLIENT_ID || 'sandbox');
})



module.exports = router;

