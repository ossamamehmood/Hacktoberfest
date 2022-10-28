import { useContext, React } from "react";
import { useParams } from "react-router-dom";
import { useState, useEffect } from "react";
import { CartContext } from "../Context";
import Pagination from "./Pagination";
import Item from "./Item";
import Oops from "./Oops";

const headerImg = {
	position: "relative",
	width: "100%",
	height: "230px",
	background:
		"url(https://image.shutterstock.com/image-photo/various-asian-meals-on-rustic-260nw-1125066479.jpg)",
	backgroundSize: "cover",
	backgroundPosition: "center",
	backgroundRepeat: "no-repeat",
	textAllign: "center",
	alignItems: "center",
	fontWeight: "bold",
};

const Restaurant = () => {
	const { id } = useParams();
	const [menu, setMenu] = useState(null);
	const [restaurant, setRestaurant] = useState(null);
	const { searchQuery } = useContext(CartContext);

	const [currentPage, setCurrentPage] = useState(1);
	const [menusPerPage] = useState(2);
	useEffect(() => {
		getMenu(id);
		async function getMenu() {
			const response = await fetch("https://my-json-server.typicode.com/moinak878/tomato/api/" + id);
			const data = await response.json();
			setMenu(data.menu);
			setRestaurant(data.name);
		}
	}, [id]);

	if (menu) {
		//menus per page
		const indexOfLastmenu = currentPage * menusPerPage;
		const indexOfFirstmenu = indexOfLastmenu - menusPerPage;
		var currentmenus = menu.slice(indexOfFirstmenu, indexOfLastmenu);
		//change page
		var paginate = (pageNumber) => setCurrentPage(pageNumber);
	}

	if (menu && searchQuery != null) {
		var transformProducts = menu.filter((item) => {
			return (
				item.name.toLowerCase().includes(searchQuery.toLowerCase().trim()) ||
				searchQuery.toLowerCase().trim().includes(item.name.toLowerCase())
			);
		});
	}
	return (
		<>
			<div className=" text-center" style={headerImg}>
				<h1 className="text-light m-auto align-self-center p-5 align-middle display-1 font-weight-bold">
					{restaurant}
				</h1>
			</div>

			{menu && searchQuery && transformProducts.length > 0 && (
				<div>
					{menu && (
						<div className="menus">
							{transformProducts.map((menu, index) => (
								<div key={index}>
									<Item menu={menu} />
								</div>
							))}
						</div>
					)}
				</div>
			)}
			{menu && searchQuery && transformProducts.length === 0 && (
				<div className="restros">
					<Oops />
				</div>
			)}
			{menu && !searchQuery && (
				<div>
					{currentmenus && (
						<div className="menus">
							{currentmenus.map((menu, index) => (
								<div key={index}>
									<Item menu={menu} />
								</div>
							))}
							<Pagination
								menusPerPage={menusPerPage}
								totalMenus={menu.length}
								paginate={paginate}
							/>
						</div>
					)}
				</div>
			)}
		</>
	);
};

export default Restaurant;
