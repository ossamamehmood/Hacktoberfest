var createError = require("http-errors");
var express = require("express");
var path = require("path");
var cookieParser = require("cookie-parser");
var logger = require("morgan");
var dotenv = require("dotenv");
var indexRouter = require("./routes/index");
var usersRouter = require("./routes/userRouter");
var productsRouter = require("./routes/productRouter");
var orderRouter = require("./routes/orderRouter");
var uploadRouter = require("./routes/uploadRouter");
var payRoute = require("./routes/payRoute");
//const isAuth = require("./middleware/authUser");

require("./db-connect/mongodb-connect.js");
dotenv.config();

const app = express();

var __dirname = path.resolve(__dirname,'../uploads');
const publicPathUrl = path.join(__dirname,'/uploads');
app.use(express.static(publicPathUrl));

app.use(logger("dev"));
app.use(express.json());
app.use(express.urlencoded({ extended: true }));
app.use(cookieParser());

app.use("/", indexRouter);
app.use("/api/users", usersRouter);
app.use("/api/products", productsRouter);
app.use("/api/orders",orderRouter);
app.use("/api/uploads",uploadRouter);
app.use("/api/pay/", payRoute)

//var __dirname = path.resolve();
//console.log("PATH:", __dirname)


// catch 404 and forward to error handler
app.use(function (req, res, next) {
  next(createError(404));

});

// error handler
app.use(function (err, req, res) {
  // set locals, only providing error in development
  res.locals.message = err.message;
  res.locals.error = req.app.get("env") === "development" ? err : {};

  // render the error page
  res.status(err.status || 500);
  res.render("error");
});

module.exports = app;
