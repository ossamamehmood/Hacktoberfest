import React from 'react'
import './App.css'
import { useSelector, useDispatch } from 'react-redux'
import {inc,dec} from './actions/index'


const App = () => {
  const myState = useSelector((state) => state.counter);
  const dispatch = useDispatch()

  return (
    <>
      <div className="container">
        <h1>Increment/Decrement counter</h1>
        <h4>using React and Redux</h4>
        <div className="quantity">
          <a className="quantityminus" title=" Decrement " onClick={() => {dispatch(dec())}}><span>-</span></a>
          <input name="quantity" type="text" className="quantityinput" value={myState} />
          <a className="quantityplus" title="Increment " onClick={() => {dispatch(inc(5))}}><span>+</span></a>
        </div>
      </div>
    </>
  )
}

export default App