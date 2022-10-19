import React from "react";
import ReactDOM from "react-dom/client";
import { BrowserRouter as Router } from "react-router-dom";
import "antd/dist/antd.min.css";
import { Provider } from "react-redux";
import store from "./app/store";

import App from "./App";

const root = ReactDOM.createRoot(document.getElementById("root"));
root.render(
  <Router>
    <Provider store={store} >
      <App />
    </Provider>
  </Router>
);