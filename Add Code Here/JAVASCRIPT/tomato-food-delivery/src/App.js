import {
	BrowserRouter as Router,
	Routes,
	Route,
	Navigate,
} from "react-router-dom";
import Header from "./components/Header.js";
import Home from "./components/Home.js";
import Cart from "./components/Cart.js";
import Login from "./components/Login.js";
import Signup from "./components/Signup.js";
import Restaurant from "./components/Restaurant.js";
import { AuthContextProvider, useAuthState } from "./firebase";
import Oops from "./components/Oops.js";

const AuthenticatedRoute = ({ children }) => {
	const { isAuthenticated } = useAuthState();
	return isAuthenticated ? children : <Navigate to="/login" />;
};

const UnauthenticatedRoute = ({ children }) => {
	const { isAuthenticated } = useAuthState();
	return !isAuthenticated ? children : <Navigate to="/" />;
};

function App() {
	return (
		<AuthContextProvider>
			<Router>
				<Header />
				<Routes>
					<Route
						path="/"
						exact
						element={
							<AuthenticatedRoute>
								<Home />
							</AuthenticatedRoute>
						}
					/>
					<Route
						path="/login"
						exact
						element={
							<UnauthenticatedRoute>
								<Login />
							</UnauthenticatedRoute>
						}
					/>
					<Route
						path="/signup"
						exact
						element={
							<UnauthenticatedRoute>
								<Signup />
							</UnauthenticatedRoute>
						}
					/>
					<Route
						path="/cart"
						exact
						element={
							<AuthenticatedRoute>
								<Cart />
							</AuthenticatedRoute>
						}
					/>
					<Route path="/:id" exact element={<Restaurant />} />
					<Route path="/oops" exact element={<Oops />} />
				</Routes>
			</Router>
		</AuthContextProvider>
	);
}

export default App;
