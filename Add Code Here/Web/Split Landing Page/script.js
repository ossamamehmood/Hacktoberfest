const outer = document.getElementById('outer');
const right = document.getElementById('right');
const left = document.getElementById('left');

left.addEventListener('mouseover',()=>{
    outer.classList.add('hover-left');
})
left.addEventListener('mouseleave',()=>{
    outer.classList.remove('hover-left');
})

right.addEventListener('mouseover',()=>{
    outer.classList.add('hover-right');
})
right.addEventListener('mouseleave',()=>{
    outer.classList.remove('hover-right');
})