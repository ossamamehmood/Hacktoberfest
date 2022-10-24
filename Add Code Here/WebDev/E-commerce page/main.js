let plusBtn = document.getElementById("plus");
let minusBtn = document.getElementById("minus");
let addBtn = document.getElementById("main-btn");
let itemNum = document.getElementsByClassName("number");
let price = document.getElementById("price");
let total = document.getElementById("total");
let badge = document.getElementById("btn-badge");
let cartBox = document.getElementById("cart-box");
let cartIcon = document.getElementById("cart-icon");
let empty = document.getElementById("empty");
let notEmpty = document.getElementById("not-empty");
itemNum[0].textContent = 0;
badge.textContent = itemNum[0].textContent;

if (Number(itemNum[0].textContent == 0)) {
  minusBtn.disabled = "true";
  addBtn.disabled = "true";
  badge.classList.remove("btn-badge");
  badge.textContent = " ";
  empty.style.display = "block";
  notEmpty.style.display = "none";
} else {
  addBtn.disabled = "";
  empty.style.display = "none";
}

cartIcon.addEventListener("click", () => {
  cartBox.classList.toggle("show-case");
});

addBtn.addEventListener("click", () => {
  alert("Item added to cart");
});

plusBtn.addEventListener("click", function () {
  for (let i = 0; i < itemNum.length; i++) {
    Number(itemNum[i].textContent++);
    getSum(itemNum[i].textContent);
    minusBtn.disabled = "";
    badge.classList.add("btn-badge");
    addBtn.disabled = "";
    badge.textContent = itemNum[i].textContent;
    empty.style.display = "none";
    notEmpty.style.display = "block";
  }
});

minusBtn.addEventListener("click", () => {
  for (let i = 0; i < itemNum.length; i++) {
    Number(itemNum[i].textContent--);
    getSum(itemNum[i].textContent);
    badge.textContent = itemNum[i].textContent;
    if (Number(itemNum[i].textContent == 0)) {
      minusBtn.disabled = "true";
      badge.classList.remove("btn-badge");
      badge.textContent = " ";
      addBtn.disabled = "true";
      empty.style.display = "block";
      notEmpty.style.display = "none";
    } else {
      minusBtn.disabled = "";
    }
  }
});

// Menu
function toggleNavbar() {
  var element = document.getElementById("mobile-menu");
  element.classList.toggle("mobile-menu-open");
}

function getSum(item) {
  total.textContent = Number(item * price.textContent);
  return;
}
