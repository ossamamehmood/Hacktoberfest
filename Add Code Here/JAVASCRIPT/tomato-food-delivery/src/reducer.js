export const reducer = (state, action) => {
	if (action.type === "ADD_ITEM") {
		if (
			state.cart.some(
				(e) => e.name === action.payload.name && e.id === action.payload.id
			)
		) {
			let updatedCart = state.cart.map((item) => {
				if (item.id === action.payload.id) {
					return {
						...item,
						qty: item.qty + 1,
					};
				}
				return item;
			});
			console.log("updatedCart", updatedCart);
			return {
				...state,
				cart: updatedCart,
				totalQty: state.totalQty + 1,
				totalAmount: state.totalAmount + Number(action.payload.price),
			};
		}
		return {
			...state,
			cart: [...state.cart, action.payload],
			totalQty: state.totalQty + 1,
			totalAmount: state.totalAmount + Number(action.payload.price),
		};
	}

	if (action.type === "REMOVE_ITEM") {
		let updatedCart = state.cart.filter(
			(item) => item.id !== action.payload.id
		);
		let { totalQty } = updatedCart.reduce(
			(accum, currVal) => {
				let { qty } = currVal;
				accum.totalQty += qty;
				return accum;
			},
			{
				totalQty: 0,
			}
		);
		let { totalAmount } = updatedCart.reduce(
			(accum, currVal) => {
				let { qty, price } = currVal;
				accum.totalAmount += price * qty;
				return accum;
			},
			{
				totalAmount: 0,
			}
		);

		return {
			...state,
			cart: updatedCart,
			totalQty: totalQty,
			totalAmount: totalAmount,
		};
	}

	if (action.type === "CLEAR_CART") {
		return {
			...state,
			cart: [],
			totalQty: 0,
			totalAmount: 0,
		};
	}

	if (action.type === "DECREMENT") {
		if (
			state.cart.some(
				(e) => e.name === action.payload.name && e.id === action.payload.id
			)
		) {
			let updatedCart = state.cart.map((item) => {
				if (item.id === action.payload.id) {
					return {
						...item,
						qty: item.qty - 1,
					};
				}
				return item;
			});
			updatedCart = updatedCart.filter((item) => item.qty !== 0);

			let { totalQty } = updatedCart.reduce(
				(accum, currVal) => {
					let { qty } = currVal;
					accum.totalQty += qty;
					return accum;
				},
				{
					totalQty: 0,
				}
			);
			let { totalAmount } = updatedCart.reduce(
				(accum, currVal) => {
					let { qty, price } = currVal;
					accum.totalAmount += price * qty;
					return accum;
				},
				{
					totalAmount: 0,
				}
			);

			return {
				...state,
				cart: updatedCart,
				totalQty: totalQty,
				totalAmount: totalAmount,
			};
		}
	}
	if (action.type === "SET_SEARCH_QUERY") {
		return { ...state, searchQuery: action.payload };
	}
	return state;
};
