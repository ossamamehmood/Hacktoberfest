import React, { useEffect, useState } from 'react';
import { Button, Menu, Avatar } from 'antd';
import { Link } from "react-router-dom";
import { HomeOutlined, BulbOutlined, FundOutlined, MenuOutlined } from "@ant-design/icons";
import icon from "../assets/cryptocurrency.png"

const Navbar = () => {

  const [activeMenu, setActiveMenu] = useState(true);
  const [screenSize, setScreenSize] = useState(null);

  useEffect(() => {
    const handleResize = () => setScreenSize(window.innerWidth);

    window.addEventListener('resize', handleResize);

    handleResize();

    return () => window.removeEventListener('resize', handleResize);
  }, [])

  useEffect(() => {
    if(screenSize < 768)
      setActiveMenu(false)
    else
      setActiveMenu(true)
  }, [screenSize])

  return (
    <div className="nav-container">
      <div className="logo-container">
        <Avatar src={icon} className="logo" />
        <Button className='menu-control-container' onClick={(() => setActiveMenu(!activeMenu))}><MenuOutlined /></Button>
      </div>
      {activeMenu && (<Menu style={{ backgroundColor: "#262322", color: "#F2E5D7" }}>
          <Menu.Item icon={<HomeOutlined className='navbar-icons'/>}>
            <Link to="/" style={{ color: "#F2E5D7" }}>
              Home
            </Link>
          </Menu.Item>
          <Menu.Item icon={<FundOutlined className='navbar-icons'/>}>
            <Link to="/cryptocurrencies" style={{ color: "#F2E5D7" }}>Cryptocurrencies</Link>
          </Menu.Item>
          {/* <Menu.Item icon={<MoneyCollectOutlined className='navbar-icons'/>}>
            <Link to="/exchanges" style={{ color: "#F2E5D7" }}>Exchanges</Link>
          </Menu.Item> */}
          {/* Exchanges api required premium plan */}
          <Menu.Item icon={<BulbOutlined className='navbar-icons'/>}>
            <Link to="/news" style={{ color: "#F2E5D7" }}>News</Link>
          </Menu.Item>
        </Menu>
      )}
    </div>
  );
}

export default Navbar