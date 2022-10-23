const mongoose = require('mongoose');

const reviewSchema = new mongoose.Schema({
  name : {type:String, required:true},
  comment : {type:String, required:true},
  rating : {type:Number, required:true},
}, {timestamps:true});

const productSchema = new mongoose.Schema({
  name : {type:String, required:true},
  seller: {type:mongoose.Schema.Types.ObjectId,ref: "User"},
  image: {type: String, required:true},
  brand: {type: String, required:true},
  category: {type: String, required:true},
  description: {type: String, required:true},
  price: {type: Number, required:true},
  countInStock: {type: Number, required:true},
  rating: {type: Number, required:true},
  numReviews: {type: Number, required:true},
  reviews:[reviewSchema]

},{
  timestamps: true,
});


const Product = mongoose.model('Product', productSchema)

module.exports = Product;