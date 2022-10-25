let card = document.querySelectorAll(".card");
let prev = document.querySelector(".prev");
let next = document.querySelector(".next");
let position = 0;

card.forEach((item, index) => {
  item.style.left = `${30 * index}px`;
});

prev.style.display = "none";

next.onclick = () => {
  prev.style.display = "block";
  position -= 140;
  changeSlider();
  if (card[0].style.transform == `translateX(${-1120}px)`) {
    next.style.display = "none";
  }
};
prev.onclick = () => {
  next.style.display = "block";
  position += 140;
  changeSlider();
  if (card[0].style.transform == `translateX(${0}px)`) {
    prev.style.display = "none";
  }
};

function changeSlider() {
  card.forEach((item) => {
    item.style.transform = `translateX(${position}px)`;
  });
}
