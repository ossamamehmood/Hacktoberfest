import { Outlet, Link } from "react-router-dom";

const Layout = () => {
  return (
    <>
      <nav>
        <ul>
          {/* <li>
            <Link to="/">Home</Link>
          </li> */}
          {/* <li>
            <Link to="/Screen_2">Screen_2</Link>
          </li> */}
        </ul>
      </nav>

      <Outlet />
    </>
  )
};

export default Layout;