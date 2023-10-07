// first take id 
const input = document.querySelector('.grocery');
const submit = document.querySelector('.submit-btn');
let nextItemId = 1; 
let todoListItems = []; 

submit.addEventListener('click', function (event) {
  event.preventDefault();
  addTodo();
  input.value = '';
  const alertMessage = document.querySelector('.alert');
  alertMessage.innerHTML = 'Product added successfully';
  alertMessage.classList.add('active-green');

  // Set a timeout to remove the alert message after 3 seconds
  setTimeout(function () {
    alertMessage.innerHTML = ''; 
    alertMessage.classList.remove('active-green');
  }, 2000); 
});


let lists = [];
// add to cart
function addTodo() {
  var valueItem = input.value.trim();

  if (valueItem !== ''){
    lists.push(valueItem);
    const itemId = nextItemId++; 
    todoListItems.push({ id: itemId, name: valueItem });
    renderTodoList();
  }else {
    showErrorMessage('Enter something'); 
    
  }
  
 
  }

// show list
function renderTodoList() {
  let todoListHTML = '';
  lists.forEach(function (todoObject, index) {
    const { name } = todoObject;
    const itemId = todoListItems[index].id; 
    const html = `
      <article class="grocery-item" data-id="${itemId}">
        <p class="title">${todoObject}</p>
        <div class="btn-container">
          <button type="button" onclick="deleteItem(${itemId})" class="delete-btn">
            <i class="fas fa-trash"></i>
          </button>
        </div>
      </article>
    `;
    todoListHTML += html;
  });
  document.querySelector('.grocery-list').innerHTML = todoListHTML;
}
// delete an item by ID
function deleteItem(itemId) {
  const index = todoListItems.findIndex(item => item.id === itemId);
  if (index !== -1) {
    lists.splice(index, 1);
    todoListItems.splice(index, 1);
    const alertMessage = document.querySelector('.alert');
    alertMessage.innerHTML = 'Product Deleted successfully';
    alertMessage.classList.add('active-red');
    setTimeout(function () {
      alertMessage.innerHTML = ''; 
      alertMessage.classList.remove('active-red');
    }, 2000);

    renderTodoList();
  }
}
