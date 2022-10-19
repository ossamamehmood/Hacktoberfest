import React from 'react';
import {Route, Link, Routes} from "react-router-dom";
import { Layout, Typography, Space } from "antd";
import "./App.css";

import { Navbar, Homepage, Cryptocurrencies, Cryptodetails, News } from "./components";

const App = () => {
  return (
    <div className="app">
      <div className="navbar">
        <Navbar />
      </div>

      <div className="main">
        <Layout>
          <div className="routes">
            <Routes>
              <Route path="/" element={<Homepage />} />
              <Route path="/cryptocurrencies" element={<Cryptocurrencies />} />
              {/* <Route path="/exchanges" element={<Exchanges />} /> */} {/* the api required premium plan */}
              <Route path="/crypto/:coinId" element={<Cryptodetails />} />
              <Route path="/news" element={<News />} />
            </Routes>
          </div>
        </Layout>

        <div className="footer">
          <Typography.Title
            level={5}
            style={{ color: "white", textAlign: "center" }}
          >
            Coin Nerd <br />
            All rights reserved
          </Typography.Title>
          <Space>
            <Link to="/" style={{ color: "#F2E5D7", fontFamily: 'Roboto' }}>Home</Link>
            <Link to="/exchanges" style={{ color: "#F2E5D7", fontFamily: 'Roboto' }}>Exchanges</Link>
            <Link to="/news" style={{ color: "#F2E5D7", fontFamily: 'Roboto' }}>News</Link>
          </Space>
        </div>
      </div>
    </div>
  );
}

export default App