import React,{useState} from 'react'
import Header from './Header'
import CreateArea from './CreateArea'
import Note from './Note'
import './App.css'

const App = () => {
const [Notes, setNotes] = useState([]);
function addNote(newNotes){
  setNotes((prevNotes)=>{
    return [...prevNotes,newNotes]
  });
 }
 function delNote(id){
  setNotes((prevNotes)=>{
    return prevNotes.filter((item,index) =>{
        return index !==id;
    });
  });

 }
 console.log(Notes)
  return (
    <div>
        <Header />
        <CreateArea addNote={addNote}/>
        {
        Notes.map((noteItem,index)=>{
          return (
          <Note key={index} title={noteItem.title} content={noteItem.content} delNote={delNote} id ={index}/>
          )
        })
        }
    </div>
  )
}

export default App
