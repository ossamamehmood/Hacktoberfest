var express = require("express");
var User = require("../models/userModel.js");
var router = express.Router();
var expressAsyncHandler = require("express-async-handler");
var bcrypt = require("bcryptjs");
const generateToken = require("../middleware/generateToken.js");
const isAuth = require("../middleware/authUser");
const isAdmin = require("../middleware/authAdmin");


router.get("/top-sellers", async(req,res)=>{
  const topSellers = await User.find({isSeller: true}).sort({'seller.rating':-1}).limit(5);
  res.send(topSellers);
})

router.post(
  "/signin",
  expressAsyncHandler(async (req, res) => {
    const user = await User.findOne({ email: req.body.email });
    if (user) {
      if (bcrypt.compareSync(req.body.password, user.password)) {
        res.send({
          _id: user._id,
          name: user.name,
          email: user.email,
          isAdmin: user.isAdmin,
          isSeller: user.isSeller,
          token: generateToken(user),
        });
        return;
      }
    }
    res.status(401).send({ message: "Invalid email or password" });
  })
);

router.post(
  "/register",
  expressAsyncHandler(async (req, res) => {
    const user = new User({
      name: req.body.name,
      email: req.body.email,
      password: bcrypt.hashSync(req.body.password, 8),
    });
    const createdUser = await user.save();
    res.send({
      _id: createdUser._id,
      name: createdUser.name,
      email: createdUser.email,
      isAdmin: createdUser.isAdmin,
      isSeller: user.isSeller,
      token: generateToken(createdUser),
    });
  })
);

router.get(
  "/:id",
  expressAsyncHandler(async (req, res) => {
    const user = await User.findById(req.params.id);
    if (user) {
      res.send(user);
    } else {
      res.status(404).send({ message: "User Not Found" });
    }
  })
);

router.put(
  "/profile",
  isAuth,
  expressAsyncHandler(async (req, res) => {
    const user = await User.findById(req.user._id);
    if (user) {
      user.name = req.body.name || user.name;
      user.email = req.body.email || user.email;
      if(user.isSeller){
        user.seller.name = req.body.sellerName || user.seller.name;
        user.seller.description = req.body.sellerDescription || user.seller.description;
        user.seller.logo = req.body.sellerLogo || user.seller.logo;
      }
      if (req.body.password) {
        user.password = bcrypt.hashSync(req.body.password, 8);
      }
      const updatedUser = await user.save();
      res.send({
        _id: updatedUser._id,
        name: updatedUser.name,
        email: updatedUser.email,
        isAdmin: updatedUser.isAdmin,
        isSeller: user.isSeller,
        token: generateToken(updatedUser),
      });
    }
  })
);

/*ADMIN*/
router.get('/',isAuth, isAdmin, expressAsyncHandler(async (req,res)=>{
  const users = await User.find({});
  if (users) {
    res.status(200).send(users);
  }else {
    res.status(404).send({message: 'Users Not Found'})
  }
}))

router.delete('/:id', isAuth, isAdmin, async(req,res)=>{
  const user = await User.findById(req.params.id)
  if(user) {
    if(user.isAdmin == true){
      res.status(400).send({message:'Can Not Delete Admin User'})
      return;
    }
    const deletedUser = await user.remove()
    res.status(200).send({message: `${user.email} Deleted`, user:deletedUser });
  }else{
    res.status(404).send({message: 'User Not Found'});
  }
})

router.put('/:id', isAuth, isAdmin, expressAsyncHandler(async(req,res)=>{
  const user = await User.findById(req.params.id)
  if(user) {
    user.name = req.body.name || user.name;
    user.email = req.body.email || user.email;
    user.isAdmin = Boolean(req.body.isAdmin);
    user.isSeller = Boolean(req.body.isSeller); 
    const updatedUser = await user.save()
    res.status(200).send({message: `${user.name} Updated`, user : updatedUser });
  }else{
    res.status(404).send({message: 'User Not Found'});
  }
}))

module.exports = router;







