import { LoadingOutlined } from "@ant-design/icons";
import { Spin } from "antd";
import React from "react";
const antIcon = (
  <LoadingOutlined
    style={{
      color: "#C69564",
      position: "absolute",
      left: "50%",
      fontSize: "28px",
    }}
    spin
  />
);

const Loader = () => <Spin indicator={antIcon} style={{padding: '100px'}}/>;

export default Loader;
