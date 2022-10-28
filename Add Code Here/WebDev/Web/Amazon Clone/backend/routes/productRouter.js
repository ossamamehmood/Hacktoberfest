var express = require("express");
var router = express.Router();
var Product = require("../models/productModel");
//const isAdmin = require("../middleware/authAdmin");
const isAuth = require("../middleware/authUser");
const isSellerOrAdmin = require("../middleware/authSeller.js");
var expressAsyncHandler = require("express-async-handler");

router.get(
  "/",
  expressAsyncHandler(async (req, res) => {
    console.log("get all products");
    const seller = req.query.seller || "";
    const name = req.query.name || "";
    const category = req.query.category || "";
    const order = req.query.order || "";
    const min =
      req.query.min && Number(req.query.min) !== 0 ? Number(req.query.min) : 0;
    const max =
      req.query.max && Number(req.query.max) !== 0 ? Number(req.query.max) : 0;
    const rating =
      req.query.rating && Number(req.query.rating) !== 0
        ? Number(req.query.rating)
        : 0;

    const nameFilter = name ? { name: { $regex: name, $options: "i" } } : {};
    const sellerFilter = seller ? { seller } : {};
    const categoryFilter = category ? { category } : {};
    /*gte = greaterThen, lte= lessThen*/
    const priceFilter = min && max ? { price: { $gte: min, $lte: max } } : {};
    const ratingFilter = rating ? { rating: { $gte: rating } } : {};
    const sortOrder =
      order === "lowest"
        ? { price: 1 }
        : order === "highest"
        ? { price: -1 }
        : order === "toprated"
        ? { rating: -1 }
        : { _id: -1 };

    const products = await Product.find({
      ...sellerFilter,
      ...nameFilter,
      ...categoryFilter,
      ...priceFilter,
      ...ratingFilter,
    })
      .populate("seller", "seller.name seller.logo")
      .sort(sortOrder);
    res.send(products);
  })
);

router.get("/categories", async (req, res) => {
  const categories = await Product.find().distinct("category");
  res.send(categories);
});

router.get(
  "/:id",
  expressAsyncHandler(async (req, res) => {
    const product = await Product.findById(req.params.id).populate(
      "seller",
      "seller.name seller.logo seller.rating seller.numReviews"
    );
    if (product) {
      res.send(product);
    } else {
      res.status(404).send({ message: "Product Not Found" });
    }
  })
);

router.post(
  "/",
  isAuth,
  isSellerOrAdmin,
  expressAsyncHandler(async (req, res) => {
    const random = Math.floor(Math.random() * 10) + 2;
    const product = new Product({
      name: "sample name" + Date.now(),
      image: `/images/p${random}.jpg`,
      seller: req.user._id,
      price: 0,
      category: "sample category",
      brand: "sample brand",
      countInStock: 0,
      rating: 0,
      numReviews: 0,
      description: "sample desc",
    });
    console.log("product created..");
    const createdProduct = await product.save();
    res
      .status(200)
      .send({ message: "Product Created", product: createdProduct });
  })
);
/*    
  setName(product.name);
  setPrice(product.price);
  setImage(product.image);
  setCategory(product.category);
  setBrand(product.brand);
  setCountInStock(product.countInStock);
  setDescription(product.description);
*/

router.put(
  "/:id",
  isAuth,
  isSellerOrAdmin,
  expressAsyncHandler(async (req, res) => {
    const productId = req.params.id;
    const product = await Product.findById(productId);
    if (product) {
      product.name = req.body.name || product.name;
      product.price = req.body.price || product.price;
      product.image = req.body.image || product.image;
      product.category = req.body.category || product.category;
      product.brand = req.body.brand || product.brand;
      product.countInStock = req.body.countInStock || product.countInStock;
      product.description = req.body.description || product.description;
      const updatedProduct = await product.save();
      res.send({ product: updatedProduct });
    } else {
      res.status(404).send({ message: "Product Doesn't exist" });
    }
  })
);

router.delete(
  "/:id",
  isAuth,
  isSellerOrAdmin,
  expressAsyncHandler(async (req, res) => {
    const productId = req.params.id;
    const product = await Product.findByIdAndRemove(productId);
    if (product) {
      res.status(200).send({ product, message: "Product Deleted" });
    } else {
      res.status(404).send({ message: "Product Not Found" });
    }
  })
);

router.post(
  "/:id/reviews",
  isAuth,
  expressAsyncHandler(async (req, res) => {
    const productId = req.params.id;
    const product = await Product.findById(productId);
    if (product) {
      if (product.reviews.find((x) => x.name === req.user.name)) {
        return res
          .status(400)
          .send({ message: "Daha önce yorum yaptınız!" });
      }
      const review = {
        name: req.user.name,
        rating: Number(req.body.rating),
        comment: req.body.comment,
      };
      product.reviews.push(review);
      product.numReviews = product.reviews.length;
      product.rating =
        product.reviews.reduce((acc, curr) => acc + curr.rating, 0) /
        product.reviews.length;
      const updatedProduct = await product.save();
      res
        .status(201)
        .send({
          message: "Review Adeed",
          review: updatedProduct.reviews[updatedProduct.reviews.length - 1],
        });
    } else {
      res.status(404).send({ message: "Product Doesn't exist" });
    }
  })
);

module.exports = router;
