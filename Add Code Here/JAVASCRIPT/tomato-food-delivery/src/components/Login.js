import { useCallback } from "react";
import { getAuth, signInWithEmailAndPassword } from "firebase/auth";
import { Row } from "react-bootstrap";
import { Link } from "react-router-dom";

export const Login = () => {
	const handleSubmit = useCallback(async (e) => {
		e.preventDefault();

		const { email, password } = e.target.elements;
		const auth = getAuth();
		try {
			await signInWithEmailAndPassword(auth, email.value, password.value);
		} catch (e) {
			alert(e.message);
		}
	}, []);

	return (
		<div>
			<Row lg={4} className="mt-5 justify-content-center ">
				<form
					className="mt-5 align-self-center justify-content-center border border-info rounded"
					onSubmit={handleSubmit}
				>
					<h1>Login</h1>
					<div className="form-group">
						<label>Email</label>
						<input
							name="email"
							className="form-control"
							placeholder="Enter your email"
							type="email"
						/>
					</div>
					<div className="form-group">
						<label>Password</label>
						<input
							name="password"
							className="form-control"
							placeholder="Enter Password"
							type="password"
						/>
					</div>
					<button className="my-3 btn btn-success btn-block" type="submit">
						Login
					</button>
				</form>
			</Row>
			<p className="mt-2 d-flex justify-content-center">
				New here ? <Link to="/signup"> Sign up</Link>
			</p>
		</div>
	);
};

export default Login;
