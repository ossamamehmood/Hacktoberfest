import { Fab, Zoom } from '@material-ui/core'
import { Add } from '@material-ui/icons'
import React, { useState } from 'react'

const CreateArea = ({addNote}) => {
 
const [isExpand,setIsExpand]=useState(false)
function expand() {
    setIsExpand(true);
}
const [note,setNote]=useState({
    title:"",
    content:"",
})
const handleChange =(event)=>{
    const {name,value}=event.target
    setNote((prevNote)=>{
        return{
            ...prevNote,
            [name]:value,
        }
    });
}
const submit =() =>{
    addNote(note);
    setNote({
        title:"",
        content:"",

    });
}

  return (
    <div>
        <form className="create-note">
        {isExpand && <input name="title" placeholder="Title" value={note.title} onChange={handleChange} />}
        <textarea 
            name="content"
            placeholder="Take a note..."
            rows={isExpand ? 3:1}
            onClick={expand} 
            value={note.content}
            onChange={handleChange} />
        <Zoom in={isExpand}>
            <Fab onClick={submit}>          
            <Add />
            </Fab>  
        </Zoom>
        </form>
    </div>
  )
}

export default CreateArea
