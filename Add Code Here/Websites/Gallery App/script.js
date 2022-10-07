const panels = document.querySelectorAll('.panel');
const btn = document.getElementById('btn');
const con = document.getElementById('container');
// console.log(panels)

panels.forEach((element)=>{
    element.addEventListener('click',()=>{
        con.classList.remove('set');;
        removeactive();
        element.classList.add('active');
       
    })
})

btn.addEventListener('click',()=>{
    panels.forEach((ele)=>{
        ele.classList.remove('active');  
        con.classList.add('set');
    })
})

    function removeactive(){
        panels.forEach((element)=>{
            element.classList.remove('active');
        })
    }