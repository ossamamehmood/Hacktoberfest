import { Delete } from '@material-ui/icons'
import React from 'react'

const Note = ({title,content,delNote,id}) => {
  return (
    <div className="note">
        <h1>{title}</h1>
        <p>{content}</p>
        <button onClick={() => delNote(id)}>
            <Delete />
        </button>
    </div>
  )
}

export default Note
