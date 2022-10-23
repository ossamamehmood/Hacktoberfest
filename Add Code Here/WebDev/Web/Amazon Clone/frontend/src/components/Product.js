/* eslint-disable no-lone-blocks */
import React from "react";
import { Link } from "react-router-dom";
import Rating from "./Rating";

export default function Product(props) { 
  const { product } = props;
  return (
    <div key={product._id} className="card">
      <Link to={`/product/${product._id}`}>
        <img className="medium" src={product.image} alt={product.name} />
      </Link>
      <div className="card-body">
        <Link to={`/product/${product._id}`}>

            <div className="product-header-wrapper">
             <h2> {product.name}</h2>
          </div>

        </Link>
        <Rating rating={product.rating} numReviews={product.numReviews} />
        <div className = "row">

          <div className="price"> ₺{product.price}</div>

          <div>
            <Link to= {`/seller/${product.seller._id}`}>{product.seller.seller.name}</Link>
          </div>
          
        </div>
        
      </div>
    </div>
  );
}

