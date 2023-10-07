var allele = document.getElementsByClassName('foodite');
var btns = document.getElementsByTagName('button');
var t = 0;

function colorChange() {
    for (let i = 0; i < btns.length; i++) {
        btns[i].style.backgroundColor = "";
    }
    this.style.backgroundColor = "black";
}

for (let k = 0; k < btns.length; k++) {
    btns[k].onclick = colorChange;
}

const but1 = document.getElementById('Basmathi_Rice');
but1.addEventListener('click',()=>{
    
    for(let j=0 ; j<allele.length;j++)
    {
        allele[j].style.display="none";
    }
    var z = document.getElementsByClassName('Basmathi_Rice');
    for(let i=0;i<z.length;i++){
        if( z[i].style.display === "inline-block")
        {
        z[i].style.display = "none";
        }
        else{
            z[i].style.display = "inline-block";
        }
    }
});

const but2 = document.getElementById('urad_dal');
but2.addEventListener('click',()=>{
    for(let j=0 ; j<allele.length;j++)
    {
        allele[j].style.display="none";
    }
    var z = document.getElementsByClassName('urad_dal');
    for(let i=0;i<z.length;i++){
        if( z[i].style.display === "inline-block")
        {
        z[i].style.display = "none";
        }
        else{
            z[i].style.display = "inline-block";
        }
    }
});

const but3 = document.getElementById('Cumin_seeds');
but3.addEventListener('click',()=>{
    for(let j=0 ; j<allele.length;j++)
    {
        allele[j].style.display="none";
    }
    var z = document.getElementsByClassName('Cumin_Seeds');
    for(let i=0;i<=z.length;i++){
        if( z[i].style.display === "inline-block"){
        z[i].style.display="none";
        }
        else{
            z[i].style.display = "inline-block";
        }
    }

})

const but4 = document.getElementById('Chiken');
but4.addEventListener('click',()=>{
    for(let j=0 ; j<allele.length;j++)
    {
        allele[j].style.display="none";
    }
    var z = document.getElementsByClassName('Chiken');
    for(let i=0;i<=z.length;i++){
        if( z[i].style.display === "inline-block"){
        z[i].style.display="none";
        }
        else{
            z[i].style.display = "inline-block";
        }
    }
});

const but5 = document.getElementById('paneer');
but5.addEventListener('click',()=>{
    for(let j=0 ; j<allele.length;j++)
    {
        allele[j].style.display="none";
    }
    var z = document.getElementsByClassName('paneer');
    for(let i=0;i<=z.length;i++){
        if( z[i].style.display === "inline-block"){
        z[i].style.display="none";
        }
        else{
            z[i].style.display = "inline-block";
        }
    }
});

