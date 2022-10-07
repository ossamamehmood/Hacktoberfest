let grids = document.querySelectorAll('div');
let num =0;

 grids.forEach(grid => {
     setTimeout(()=> {
     grid.style.backgroundColor = 'blue';
     }, num+=100);
 })