import { useCallback } from "react";
import { getAuth, createUserWithEmailAndPassword } from "firebase/auth";
import { Row } from "react-bootstrap";
import { Link } from "react-router-dom";

export const SignUp = () => {
	const handleSubmit = useCallback(async (e) => {
		e.preventDefault();

		const { email, password } = e.target.elements;
		const auth = getAuth();
		try {
			await createUserWithEmailAndPassword(auth, email.value, password.value);
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
					<h1>Sign up</h1>
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
						Sign up
					</button>
				</form>
			</Row>
			<p className="mt-2 d-flex justify-content-center">
				Already have an account ? <Link to="/login">Log in</Link>
			</p>
		</div>
	);
};

export default SignUp;
