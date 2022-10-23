const isSeller = (req, res, next) => {
  if(req.user && req.user.isSeller){
    next();
  }else {
    res.status(401).send({message: 'Invalid Seller Token'})
  }
}

const isSellerOrAdmin = (req, res, next) => {
  if(req.user && (req.user.isSeller || req.user.isAdmin)){
    next();
  }else {
    res.status(401).send({message: 'Invalid Admin/Seller Token'})
  }
}


module.exports = isSellerOrAdmin, isSeller;