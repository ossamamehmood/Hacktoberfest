import { useState, useEffect, useContext } from "react";
import { CartContext } from "../Context";
import { Link } from "react-router-dom";
import { FormControl, Card, Button } from "react-bootstrap";
import Oops from "./Oops";
const tomato = require("./tomato.png").default;
const Home = () => {
	const { searchQuery, setSearchQuery } = useContext(CartContext);
	const headerImg = {
		position: "relative",
		width: "100%",
		height: "300px",
		background:
			"url(https://images.all-free-download.com/images/graphiclarge/purple_mountain_sunset_193218.jpg)",
		backgroundSize: "cover",
		backgroundPosition: "center",
		backgroundRepeat: "no-repeat",
	};
	const [restro, setRestro] = useState(null);
	useEffect(() => {
		getData();
		async function getData() {
			const response = await fetch("https://my-json-server.typicode.com/moinak878/tomato/api/");
			const data = await response.json();
			setRestro(data);
		}
	}, []);

	if (restro && searchQuery != null) {
		var transformRestros = restro.filter((item) => {
			return (
				item.name.toLowerCase().includes(searchQuery.toLowerCase().trim()) ||
				searchQuery.toLowerCase().trim().includes(item.name.toLowerCase())
			);
		});
	}

	return (
		<div>
			<div className=" text-center" style={headerImg}>
				<img
					className="text-light mt-5 col-md-4 align-self-center"
					src={tomato}
					alt="tomato"
				/>
				<p className="text-light m-auto font-weight-bold align-self-center">
					Discover the best food & drinks in Durgapur
				</p>
				<FormControl
					className="mt-2 mx-auto align-self-center justify-content-center "
					style={{ width: "500px" }}
					placeholder="Search over 100+ Restaurants"
					onChange={(e) => setSearchQuery(e.target.value)}
				/>
			</div>

			{restro && searchQuery && transformRestros.length > 0 && (
				<div className="restros d-flex m-5">
					{transformRestros.map((restro, index) => (
						<div key={index}>
							<Card
								style={{ width: "20rem", margin: "2rem" }}
								className="border"
							>
								<Card.Img
									variant="top"
									src="https://b.zmtcdn.com/data/pictures/9/19517719/67af9386f70f374b509bc11311917a43_o2_featured_v2.jpg?output-format=webp"
								/>
								<Card.Body>
									<Card.Title>{restro.name}</Card.Title>
									<Card.Text>Biryani,North Indian</Card.Text>
									<Button variant="outline-secondary">
										<Link
											to={`/${index + 1}`}
											className="btn "
											onClick={() => setSearchQuery(null)}
										>
											See Menu
										</Link>
									</Button>
								</Card.Body>
							</Card>
						</div>
					))}
				</div>
			)}
			{restro && searchQuery && transformRestros.length === 0 && (
				<div className="restros">
					<Oops />
				</div>
			)}

			{restro && !searchQuery && (
				<div className="d-flex justify-content-around m-5 restros">
					{restro.map((restro, index) => (
						<div key={index}>
							<Card style={{ width: "20rem" }} className="border">
								<Card.Img
									variant="top"
									src="https://b.zmtcdn.com/data/pictures/9/19517719/67af9386f70f374b509bc11311917a43_o2_featured_v2.jpg?output-format=webp"
								/>
								<Card.Body>
									<Card.Title>{restro.name}</Card.Title>
									<Card.Text>Biryani,North Indian</Card.Text>
									<Button variant="outline-secondary">
										<Link
											to={`/${index + 1}`}
											className="btn "
											onClick={() => setSearchQuery(null)}
										>
											See Menu
										</Link>
									</Button>
								</Card.Body>
							</Card>
						</div>
					))}
				</div>
			)}
		</div>
	);
};

export default Home;
