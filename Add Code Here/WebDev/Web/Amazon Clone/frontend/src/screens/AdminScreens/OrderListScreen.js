import React, { useEffect } from "react";
import { useDispatch, useSelector } from "react-redux";
import { deleteOrder, listOrders } from "../../actions/orderActions";
import { ORDER_DELETE_RESET } from "../../constants/orderConstants";
import LoadingBox from "./../../components/LoadingBox";
import MessageBox from "./../../components/MessageBox";

export default function OrderListScreen(props) {
  const sellerMode = props.match.path.indexOf("/seller") >= 0;
  const orderList = useSelector((state) => state.orderList);
  const { loading, error, orders } = orderList;
  
  const orderDelete = useSelector(state => state.orderDelete);
  const {loading: loadingDelete, error:errorDelete, success: successDelete} = orderDelete;
  const dispatch = useDispatch();

  const userSignin = useSelector((state) => state.userSignin);
  const { userInfo } = userSignin;

  useEffect(() => {
    dispatch({type: ORDER_DELETE_RESET})
    dispatch(listOrders({ seller: sellerMode ? userInfo._id : '' }));
  }, [dispatch,successDelete,sellerMode,userInfo._id]);
  
  const deleteHandler = (order) => {
    if (window.confirm("Do you want to delete this order?")) {
      dispatch(deleteOrder(order._id));
    }
  };
  return (
    <div>
      <h1>ORDERS</h1>
      {loadingDelete && <LoadingBox></LoadingBox>}
      {errorDelete && <MessageBox variant="danger">{errorDelete}</MessageBox>}
      {loading ? (
        <LoadingBox></LoadingBox>
      ) : error ? (
        <MessageBox variant="danger">{error}</MessageBox>
      ) : (
        <table className="table">
          <thead>
            <tr>
              <th>ID</th>
              <th>USER</th>
              <th>DATE</th>
              <th>TOTAL</th>
              <th>PAID</th>
              <th>DELIVERED</th>
              <th>ACTIONS</th>
            </tr>
          </thead>
          <tbody>
            {orders.map((order) => (
              <tr key={order._id}>
                <td>{order._id}</td>
                <td>{order.user.name}</td>
                <td>{order.createdAt.substring(0, 10)}</td>
                <td>{order.totalPrice.toFixed(2)}</td>
                <td>{order.isPaid ? order.paidAt : "No"}</td>
                <td>{order.isDelivered ? order.deliveredAt : "No"}</td>
                <td>
                  <button
                    type="button"
                    className="small"
                    onClick={() => {
                      props.history.push(`/order/${order._id}`);
                    }}
                  >Details
                  </button>
                  <button
                    type="button"
                    className="small"
                    onClick={() => deleteHandler(order)}
                  >Delete
                  </button>
                </td>
              </tr>
            ))}
          </tbody>
        </table>
      )}
    </div>
  );
}