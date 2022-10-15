// Trying my react assignment here
// It required Api fetch as props to get output you can create new object if you want to try out yourself Thankyou for the opprtunity

//  ---> Code starts here

// import logo from './logo.svg';
import './App.css';
import { useState } from 'react';


function App(props) {
  
const [notes, setNotes] = useState(props.notes)
const [newNote, setNewNote] = useState('')
const [showAll, setShowAll] = useState(true);


const submitNote =(event)=>{
  event.preventDefault();
  const noteObject = {
    id:notes.length +=1,
    content:newNote,
    date: new Date().toISOString(),
    important:Math.random() < 0.5
  
  }
  setNotes(notes.concat(noteObject))
  setNewNote('');
}
const handleNotChanged =(event)=>{
  setNewNote(event.target.value);
  console.log(event.target.value);
}

const notesToShow = showAll? notes :notes.filter(note => note.important)
// const [notes]=props
  return (
    <div className="App">
      <h1>Notes</h1><div>
        <button onClick={()=>setShowAll(!showAll)}>show {showAll?'Important':'all'} </button>
      </div>
      <ul>
        {notesToShow.map(note =>{
          return <li key={note.id} >{note.content}</li>
        })}
      </ul>
      <form action="" onSubmit={submitNote}>

      <label htmlFor="entry"></label>
      <input type="text" name="entry" id="entry"
       onChange={handleNotChanged}
       value={newNote} />
      <button target='submit'>show</button>
       </form>
    </div>
  );
}

export default App;
