import { React, useContext } from "react";
import { Card, Button } from "react-bootstrap";
import { CartContext } from "../Context";
import { FaPlus, FaMinus, FaTrash } from "react-icons/fa";
const Item = ({ menu }) => {
	const { cart, addToCart, removeFromCart, decrement } =
		useContext(CartContext);

	return (
		<div>
			<Card className=" d-flex m-auto my-4" style={{ width: "75rem" }}>
				<Card.Body className="d-flex ">
					<img
						className=" rounded"
						style={{ width: "200px", height: "150px" }}
						src="https://b.zmtcdn.com/data/dish_photos/cdb/d77c370349c174e0ff22a35c072decdb.jpg"
						alt="food pic"
					/>
					<div
						className="d-flex flex-column"
						style={{ width: "300px", height: "150px" }}
					>
						<Card.Title
							className=" font-weight-bold mx-5 mt-4"
							style={{ width: "300px" }}
						>
							{menu.name}

							{cart.map((item) => (
								<span style={{ margin: "5px", color: "purple" }}>
									{item.name === menu.name ? " x " + item.qty : null}
								</span>
							))}
						</Card.Title>
						<Card.Text className="mx-5">Rs. {menu.price}</Card.Text>
					</div>

					<div
						className="align-center col-md-3 offset-md-5 mt-3 "
						style={{ width: "150px" }}
					>
						<div className="d-flex ">
							<Button
								variant="outline-success"
								style={{ margin: "5px" }}
								onClick={() => addToCart(menu)}
							>
								<FaPlus className="m-1" />
							</Button>

							<Button
								variant="outline-danger "
								style={{ margin: "5px" }}
								onClick={() => decrement(menu)}
							>
								<FaMinus className="m-1" />
							</Button>
						</div>
						<div className=" d-flex">
							{cart.some((e) => e.name === menu.name && e.id === menu.id) && (
								<Button
									style={{ height: "40px", width: "60px", marginLeft: "35px" }}
									variant="outline-secondary mt-4"
									onClick={() => removeFromCart(menu)}
								>
									<FaTrash className="m-1" />
								</Button>
							)}
						</div>
					</div>
				</Card.Body>
			</Card>
		</div>
	);
};

export default Item;
