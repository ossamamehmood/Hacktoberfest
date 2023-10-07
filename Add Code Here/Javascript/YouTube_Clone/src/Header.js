import React, { useState } from 'react'
import MenuIcon from '@mui/icons-material/Menu';
import SearchIcon from '@mui/icons-material/Search';
import VideoCallIcon from '@mui/icons-material/VideoCall';
import AppsIcon from '@mui/icons-material/Apps';
import NotificationsIcon from '@mui/icons-material/Notifications';
import { Avatar } from '@mui/material';
import {Link} from "react-router-dom"
//  import Avatar from '@mui/icons-material/Avatar';
import './Header.css';

function Header() {
  const [inputSearch, setInputSearch]= useState('');

  return (
    <div className='header' >
      {/* <h1>I am header</h1> */}
      <div className="header_left">
        <MenuIcon />
        <img className='header_logo' src="https://www.nicepng.com/png/detail/891-8915842_youtube-logo-free-png-small-youtube-logo-png.png" alt="" />
      </div>




      <div className="header_input">
         <input onChange={(e) => setInputSearch(e.target.value)} value={inputSearch} placeholder='Search' type="text" />
        <Link to={`/search/${inputSearch}`}>
        <SearchIcon  className='header_inputButton'/>
        </Link>
      </div>







      <div className="header_icons">
        <VideoCallIcon className='header_icon'/>
        <AppsIcon className='header_icon'/>
        <NotificationsIcon className='header_icon'/>
        <Avatar />
      </div>
    </div>
  )
}

export default Header
