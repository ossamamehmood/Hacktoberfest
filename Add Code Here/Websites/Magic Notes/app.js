// localStorage.clear();
const addBtn = document.getElementById('addBtn');
const cardno = document.getElementById('cardno');
let textarea = document.getElementById('text');
let counter=0;

addBtn.addEventListener('click',getdata);

function getdata(){
    let notevalue = textarea.value;             //Getting the data what user entered
    let localnotes = localStorage.getItem('notes');

    if(localnotes == null){
        notesarr = [];
    }
    else{
        notesarr = JSON.parse(localnotes);
    }
    notesarr.push(notevalue);
    localStorage.setItem("notes",JSON.stringify(notesarr));

    textarea.value='';
    shownotes();
    }

    function shownotes(){
        let localnotes = localStorage.getItem('notes');

        if(localnotes == null){
            notesarr = [];
        }
        else{
            notesarr = JSON.parse(localnotes);
        }
        cardno.classList.remove('hide');
        let html = "";
        notesarr.forEach(function(element,index){
            html += `<div class="card hide" id="cardno">
            <div class="card-content">
                <h3 id="heading"></h3>
                <p id="paragraph"></p>
            </div>
        </div>`;
        });

        let notes = document.getElementById('notes');
        notes.innerHTML = html;

    }