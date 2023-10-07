import React from 'react';
import Header from "./Header";
import './App.css';
import Sidebar from './Sidebar';
import RecommdendedVideos from './RecommdendedVideos';
import { BrowserRouter as Router, Switch, Route } from 'react-router-dom';
import SearchPage from './SearchPage';


function App() {
  return (
    <div className="App">
      <Router >
      <Header />

        <Switch>
          <Route path='/search'>
          <div className="app_page">
            <Sidebar />
            <SearchPage />
          </div> 
          </Route>
          <Route path='/'>
             
            <div className="app_page">
            <Sidebar />
            <RecommdendedVideos />
          </div> 
          </Route>
        </Switch>
      </Router>




    

       {/* these 3 are components */}
    </div>
  );
}

export default App;
