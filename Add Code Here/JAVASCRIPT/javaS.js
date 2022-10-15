/*alert ("Warning");

let age = 30;
/console.log(age);

const a ="Azna";
let age =21;
const rating =4.5;
const isCool= true;
const x = null;

/*console.log(typeof age);
console.log(typeof a);
console.log(typeof rating);
console.log(typeof x);

document.write (rating);
document.write (a);

document.write('My name is ' + a + '  and my age is '+ age); 
console.log(`My name is ${a} and my age is ${age}`);
document.write(`My name is ${a} and my age is ${age}`);
console.log(a.toUpperCase());
console.log(a.length);
console.log(a.split(''));
//Array
const cars= ['mercedez', 'civic', 'corolla'];
cars.push('mehran');
cars.unshift('truck');
//cars.pop('mercedez');
console.log(cars);
console.log(cars.indexOf('mehran'));

//Multi Array 
const Profile ={
    fname: 'azna',
    lname: 'ijaz',
    age: 21,
    city: 'Lahre',
    hobbies: ['moives', 'cricket', 'music'],
    education:
    {
        matric: 'Done',
        inter: 'Done ',
        Bscs: '7 semester',
        Mscs: 'Inshallah '
    }
}
Profile.email = 'aznaijaz615@gmail.com';
//console.log(Profile.education.Bscs.toUpperCase());
//console.log(Profile.hobbies[2]);
console.log(Profile);




//Todos array
const todos =[
{
    id:1,
    text:'heyyyyy',
    iscompleted: true
},
{
    id:1,
    text:'hiiiiiii',
    iscompleted: false
},
{
    id:1,
    text:'hellooooooo',
    iscompleted: true
}
];

/*console.log(todos[1].text);


const todosJSON =JSON.stringify(todos);
console.log(todosJSON);


let azna= confirm("Add to cart this beautiful dress.")
if (azna){
    console.log("Add to card");

}else{
    console.log("Cant add to card beacuse your card is empty.");
}

//for loop
for(let i=0;i<5;i++){
    console.log(`For loop number: ${i}`);
}


//while
let j = 0;
while(j<5){
    console.log(`while loop j: ${j}`);
    j++;
}
/*for (let todo of todos){
    console.log(todo.text);
}

todos.forEach(function(todo){
    console.log(todo.id);
});
const todoText =todos.map(function(todo){
return todo.text;
});
console.log(todoText);



const todoCompleted =todos.filter(function(todo){
    return todo.iscompleted === true;
    }) .map(function(todo){
        return todo.text;
    })
    console.log(todoCompleted);
    
 const ja =10;
 const ka =12;
//&& 
if (ja >9 && ka >11)
{
    console.log('You re typing right.');
}


const xa= 12;
const color = xa<  12? 'red': 'blue';
//console.log(color);
switch(color){
    case 'red':
    console.log('color is red');
    break;
    case 'blue':
        console.log('color is blue');
        break;
       default:
            console.log('color is not red nor blue.');
}

function addnum (num1,num2){

    console.log(num1+num2);
}
addnum(7,7);



///OOP constructor 
function Person (f_n,l_n,dob)
{
    this.f_n = f_n;
    this.l_n = l_n;
    this.dob = dob;

    this.getFullName= function(){ 
        return `${this.f_n} ${this.l_n}`;
    }

}*/
 /*classsssssssssssssss

 class Person{

    constructor(f_n,l_n,dob){
        this.f_n = f_n;
        this.l_n = l_n;
        this.dob = new Date(dob);
    }
    getBirthYear(){
        return this.dob.getFullYear();
    }

    getFullName= function(){ 
        return `${this.f_n} ${this.l_n}`;
    }
 }

//obj
const person1 = new Person('Azna','Ijaz', '2001');
const person2 = new Person('Mi','hong', '2256')
const person3 = new Person('yang','cha', '12-16-2001')


console.log(person1);
console.log(person3.dob);
console.log(person1.getFullName());




// Built in constructors
const name = new String('Kevin');
console.log(typeof name); // Shows 'Object'
const num = new Number(5);
console.log(typeof num); // Shows 'Object'


// ES6 CLASSES
class Person {
  constructor(firstName, lastName, dob) {
    this.firstName = firstName;
    this.lastName = lastName;
    this.dob = new Date(dob);
  }

  // Get Birth Year
  getBirthYear() {
    return this.dob.getFullYear();
  }

  // Get Full Name
  getFullName() {
    return `${this.firstName} ${this.lastName}`
  }
}

const person1 = new Person('John', 'Doe', '7-8-80');
console.log(person1.getBirthYear());


// ELEMENT SELECTORS

// Single Element Selectors
console.log(document.getElementById('my-form'));
console.log(document.querySelector('.container'));
// Multiple Element Selectors
console.log(document.querySelectorAll('.item'));
console.log(document.getElementsByTagName('li'));
console.log(document.getElementsByClassName('item'));

const items = document.querySelectorAll('.item');
items.forEach((item) => console.log(item));


// MANIPULATING THE DOM
const ul = document.querySelector('.items');
// ul.remove();
// ul.lastElementChild.remove();
ul.firstElementChild.textContent = 'Hello';
ul.children[1].innerText = 'Brad';
ul.lastElementChild.innerHTML = '<h1>Hello</h1>';

const btn = document.querySelector('.btn');
// btn.style.background = 'red';


// EVENTS

// Mouse Event
btn.addEventListener('click', e => {
  e.preventDefault();
  console.log(e.target.className);
  document.getElementById('my-form').style.background = '#ccc';
  document.querySelector('body').classList.add('bg-dark');
  ul.lastElementChild.innerHTML = '<h1>Changed</h1>';
});

// Keyboard Event
const nameInput = document.querySelector('#name');
nameInput.addEventListener('input', e => {
  document.querySelector('.container').append(nameInput.value);
});
*/

// USER FORM SCRIPT

// Put DOM elements into variables
const myForm = document.querySelector('#my-form');
const nameInput = document.querySelector('#name');
const emailInput = document.querySelector('#email');
const msg = document.querySelector('.msg');
const userList = document.querySelector('#users');

// Listen for form submit
myForm.addEventListener('submit', onSubmit);

function onSubmit(e) {
  e.preventDefault();
  
  if(nameInput.value === '' || emailInput.value === '') {
    // alert('Please enter all fields');
    msg.classList.add('error');
    msg.innerHTML = 'Please enter all fields';

    // Remove error after 3 seconds
    setTimeout(() => msg.remove(), 3000);
  } else {
    // Create new list item with user
    const li = document.createElement('li');

    // Add text node with input values
    li.appendChild(document.createTextNode(`${nameInput.value}: ${emailInput.value}`));

    // Add HTML
    // li.innerHTML = `<strong>${nameInput.value}</strong>e: ${emailInput.value}`;

    // Append to ul
    userList.appendChild(li);

    // Clear fields
    nameInput.value = '';
    emailInput.value = '';
  }
}