import "./styles.css";
import { React, useContext } from "react";
import { getAuth, signOut } from "firebase/auth";
import { useAuthState } from "../firebase";
import {
	Container,
	Navbar,
	Nav,
	Dropdown,
	Badge,
	FormControl,
	Button,
} from "react-bootstrap";
import { FaShoppingCart } from "react-icons/fa";
import { Link } from "react-router-dom";
import { CartContext } from "../Context";

const theBlur = {
	width: "100%",
	minHeight: "50px",
	zIndex: 1010,
	filter: "blur(0px)",
	background:
		"url(https://hdwallpapers.cat/wallpaper_mirror/purple_harmony_sky_mountains_sunset_nature_hd-wallpaper-1913939.jpg)",
	backgroundAttachment: "scroll",
	backgroundRepeat: "no-repeat",
};

const Header = () => {
	const { cart, totalQty, setSearchQuery } = useContext(CartContext);
	const { user } = useAuthState();
	return (
		<>
			<Navbar style={theBlur} bg="dark" variant="dark">
				<Container>
					<Nav>
						<Navbar.Brand>
							<Link
								className="text-light text-decoration-none"
								to="/"
								onClick={() => setSearchQuery(null)}
							>
								Tomato
							</Link>
						</Navbar.Brand>
						<Nav.Link>
							<Link className="text-light text-decoration-none" to="/cart">
								Cart
							</Link>
						</Nav.Link>
					</Nav>
					<Nav className="m-auto">
						<FormControl
							style={{ width: "300px" }}
							placeholder="Search an item"
							onChange={(e) => setSearchQuery(e.target.value)}
						/>
					</Nav>
					<Nav>
						<Dropdown alignRight style={{ marginRight: 10 }}>
							<Dropdown.Toggle variant="outline-success">
								<FaShoppingCart color="white" />
								<Badge style={{ margin: 1 }} bg="info">
									{totalQty}
								</Badge>
							</Dropdown.Toggle>
							<Dropdown.Menu style={{ minWidth: 210 }}>
								{cart.map((item) => (
									<div style={{ padding: 10 }}>
										<strong>{item.name}</strong> - Rs {item.price} x{" "}
										<span style={{ color: "red" }}>{item.qty}</span>
									</div>
								))}
								{cart.length === 0 ? (
									<span style={{ padding: 10 }}>Cart is empty!</span>
								) : null}
							</Dropdown.Menu>
						</Dropdown>
					</Nav>
					<Nav>
						{user ? (
							<Button
								variant="outline-danger"
								onClick={() => signOut(getAuth())}
							>
								Sign out
							</Button>
						) : (
							<Link to="/login">
								<Button variant="outline-success">Sign in</Button>
							</Link>
						)}
					</Nav>
				</Container>
			</Navbar>
		</>
	);
};

export default Header;
