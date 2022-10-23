import counter from './Updown'
import { combineReducers } from 'redux'

const rootReducers = combineReducers({
    counter:counter
})


export default rootReducers