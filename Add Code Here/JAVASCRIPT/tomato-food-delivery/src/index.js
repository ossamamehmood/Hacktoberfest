import React from "react";
import ReactDOM from "react-dom";
import "./index.css";
import App from "./App";
import "bootstrap/dist/css/bootstrap.min.css";
import Context from "./Context";

ReactDOM.render(
	<Context>
		<App />
	</Context>,
	document.getElementById("root")
);
