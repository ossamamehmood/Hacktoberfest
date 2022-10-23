import React, { useEffect } from "react";
import "react-responsive-carousel/lib/styles/carousel.min.css";
import Product from "../components/Product";
import { Carousel } from "react-responsive-carousel";
import LoadingBox from "./../components/LoadingBox";
import MessageBox from "./../components/MessageBox";
import { useDispatch, useSelector } from "react-redux";
import { listProducts } from "./../actions/productActions";
import { listTopSellers } from "../actions/userActions";
import { Link } from "react-router-dom";

export default function HomeScreen() {
  const dispatch = useDispatch();
  /*fetch data from backend with axios*/

  const productList = useSelector((state) => state.productList);
  const { loading, error, products } = productList;

  const userTopSellersList = useSelector((state) => state.userTopSellersList);
  const {
    loading: loadingSellers,
    error: errorSellers,
    users: sellers,
  } = userTopSellersList;

  useEffect(() => {
    dispatch(listProducts({}));
    dispatch(listTopSellers());
  }, [dispatch]);

  return (
    <div>
      {loadingSellers ? (
        <LoadingBox></LoadingBox>
      ) : errorSellers ? (
        <MessageBox variant="danger">{errorSellers}</MessageBox>
      ) : (
        <>
          {sellers.length === 0 && <MessageBox>No Sellers Found</MessageBox>}

          <Carousel
            showThumbs={false}
            showStatus={false}
            infiniteLoop={true}
            autoPlay={true}
            interval={5000}
            transitionTime={1000}
            height = {1200}
          >
            {sellers.map((seller) => (
                <div key={seller._id}>
                  <Link to={`/seller/${seller._id}`}>
                    <img src={seller.seller.logo} alt={seller.seller.name}/>
                    {/*<p className="legend">{seller.seller.name}</p>*/}
                  </Link>
                </div>
            ))}
          </Carousel>
        </>
      )}
      {loading ? ( //first of all loading loading box if error exist then opening to message box component in to error, if doesn't exist any error opening the products.
        <LoadingBox></LoadingBox>
      ) : error ? (
        <MessageBox variant="danger">{error}</MessageBox>
      ) : (
        <>
          {products.length === 0 && <MessageBox>No Product Found</MessageBox>}
          <div className="row center">
            {products.map((product) => (
              <Product key={product._id} product={product} />
            ))}
          </div>
        </>
      )}
    </div>
  );
}
