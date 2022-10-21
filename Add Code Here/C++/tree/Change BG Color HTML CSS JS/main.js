const button = document.querySelector('button');
const h2El = document.querySelector('h2');
const bgEl = document.querySelector('section');
// const hexColorEl = [1,2,3,4,5,6,7,8,9,'A','B','c','D','E','F'];

button.addEventListener('click', () => {
  let color = '#';
  color += Math.random().toString(16).slice(2, 8).toUpperCase();
  // for(i=0; i<6; i++){
  //   const number = Math.floor(Math.random()*hexColorEl.length);
  //   color += hexColorEl[number];
  // }
  // console.log(color)
  bgEl.style.backgroundColor = color;
  h2El.innerText = color
});
