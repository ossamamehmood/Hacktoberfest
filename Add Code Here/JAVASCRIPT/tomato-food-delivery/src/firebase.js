import { initializeApp } from "firebase/app";
import { getAuth, onAuthStateChanged } from "firebase/auth";
import { useState, useEffect, useContext, createContext } from "react";

export const firebaseApp = initializeApp({
	apiKey: "AIzaSyA7lUvVD5BAAQ1cnCNL2bDYL9IEyiDU55g",
	authDomain: "tomato-b931e.firebaseapp.com",
	projectId: "tomato-b931e",
	storageBucket: "tomato-b931e.appspot.com",
	messagingSenderId: "851222690281",
	appId: "1:851222690281:web:ed1fa43790b759b1b43378",
	measurementId: "G-MX5ZDT90EJ",
});

export const AuthContext = createContext();

export const AuthContextProvider = (props) => {
	const [user, setUser] = useState(null);
	const [error, setError] = useState(true);
	useEffect(() => {
		const unsubscribe = onAuthStateChanged(getAuth(), setUser, setError);
		return () => unsubscribe();
	}, []);
	return <AuthContext.Provider value={{ user, error }} {...props} />;
};

export const useAuthState = () => {
	const auth = useContext(AuthContext);
	return { ...auth, isAuthenticated: auth.user != null };
};
