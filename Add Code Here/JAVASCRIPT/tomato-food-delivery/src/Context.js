import React, { useReducer } from "react";
import { createContext } from "react";
import { reducer } from "./reducer";

export const CartContext = createContext();

const initialState = {
	cart: [],
	totalAmount: 0,
	totalQty: 0,
	searchQuery: "",
};

const Context = ({ children }) => {
	// const [cart, setCart] = useState([]);
	const [state, dispatch] = useReducer(reducer, initialState);
	//to add an element to the cart
	const addToCart = (menu) => {
		return dispatch({
			type: "ADD_ITEM",
			payload: menu,
		});
	};
	//to remove an element from the cart
	const removeFromCart = (menu) => {
		return dispatch({
			type: "REMOVE_ITEM",
			payload: menu,
		});
	};
	//to remove an element from the cart
	const decrement = (menu) => {
		return dispatch({
			type: "DECREMENT",
			payload: menu,
		});
	};
	//to clear all items from the cart
	const clearCart = (menu) => {
		return dispatch({
			type: "CLEAR_CART",
		});
	};
	const setSearchQuery = (query) => {
		return dispatch({
			type: "SET_SEARCH_QUERY",
			payload: query,
		});
	};
	return (
		<CartContext.Provider
			value={{
				...state,
				addToCart,
				removeFromCart,
				clearCart,
				decrement,
				setSearchQuery,
			}}
		>
			{children}
		</CartContext.Provider>
	);
};

export default Context;
