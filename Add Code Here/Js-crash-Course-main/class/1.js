// console.log('Hello everyone');

// // <!-- variables, constants and comments  -->
// const store=34;

// // declaration
// console.log(store); //redcleration
// // console.log(store);
// //  var Rahul=19;
// //  console.log(Rahul);
//  // reassign

//  // constants

//  const value=10;
//  console.log(value);
//  //Data types of values

//  // 7 data types

//  //1.  Numbers 1,2,55 3.4
//  // string "I am string", "34"

//  // Boolean true/false
//  // null  Intentionally absence of values

//  let score=null;
//  console.log(score);

//  // undefined variable declared but not initialized

//  // object complex data structure
//  // symbols looks like object

//  // strings
//  console.log('Hello Coders');

//  let firstName='full stack'
//  let lastName='DEVELOPER'
//  console.log(firstName,lastName);

//  // string concatenation

//  // method using +  operator

// //  let fullName= firstName + " " + lastName;
// //  console.log(fullName);

//  // method 2 template literals
//   let fullName=`I want to become ${firstName} ${lastName}`;
//   console.log(fullName);

//   // string characters
//   console.log(firstName[5]);

//   // string methods
//    console.log(firstName.toUpperCase());
// // console.log(firstName.toLowerCase());

// // console.log(typeof firstName);
// console.log(firstName.indexOf('f'));
// let subjects=  'Science math english';
// console.log(firstName.trim());
// console.log(subjects.lastIndexOf("Science"));

// // includes
// console.log(subjects.includes('Math'));

// /// slice & splice
// let kunal='programmer';
// console.log(kunal.slice(0,6));
// // strings are immutable
// let languages=['Hindi', 'English', 'Math'];
// let kirna=languages.splice(0,1);
// console.log(kirna);
// console.log(languages);
// console.log(kunal)

// let str='Hello';
// str[0]='p';
//  console.log(str);
// str=str+'Nikhil'
// str+='Nikhil';
// console.log(str);
//  let scor=35;
// // let result=scor%5;

// // console.log(result);

// let result = scor *2 + (4*3)-8/2 + 4 // 70+ 12 -4+4
// console.log(result);

// // using priority and precedence

// // 1. () Bracket
// // 2. ** Power operator
// // 3. / % (from left to right)
// // 4. + - (from left to right)

// // loose equality and looseless equalty
// let age=24; //number
// console.log(age === 24);

// // looseless -> stict equality

// // Type conversion
//  let stringType='45';
//  console.log(stringType, typeof stringType);
//  //  number
//  let  numberType=String(stringType);
//  console.log(numberType, typeof numberType);

//  // number type method, string must be of numeric value

//  // Boolean method  (true/false)

//  let ag= '' ; // empty string
//  let booleanValue=Boolean(ag);
//  console.log("Boolean value of age is:", booleanValue);

//  // Arrays

//  let dish= ['Paneer', 'Chat', 'Oats'];
//  // access
//   console.log(dish[2]);

//   dish[0]= 'puri';
//   console.log(dish);

//   // Array methods

//   // join method
//   console.log(dish.join(','))  // ('') -> selectors

//   console.log(dish.indexOf('Chat'));

//   // concat method
// let newDish=['Rasgulla', 'Mango'];
//   console.log(dish.concat(newDish));

//   // length method
//   console.log(dish.length);

// // push method
// console.log(newDish.push('Dosa'));
// console.log(newDish);

// // pop method
// console.log(newDish.pop('Dosa'));
// console.log(newDish);

// console.log(dish);

// Boolean values and Comparison operator

// Operators
// 1.Assignment operator -> =, +=,-=, *=, /=, %=, **= , x **=y,
// 2. adddition operator, multiplication, divison, subtraction, modulas (%), increment ++ ,decrement -- ** exponential -> Arithmetic operator
// 3. Comparison operator ->  ===,==, !=, !== (not equal value or not equal type), >, <, >=, <=, ? (ternary operator)
// string compare ->
// let a='aman';
// let b='raghav';

// let res = a>b;
// console.log(res);
// let a = 5;

// let b = 7;

// let c = 8;

// let r = a < b > c;
//  console.log(r);

//  // string concatenation
//  let x=2+3;
//  let y= "A"+ 3;
//  let z= 'Hello' + 1;
//  let q= z+y+x;
//  console.log(q);
// console. log( typeof z, typeof q);

// 4. logical operator -> && (logical and), || (logical or), ! (logical not)

// -> type operator
// typeof -> returns type of variable
//  instanceof -> return true  if an object is an instance of an onject type

//  bitwise operator -> &, |, ~ (not), << (left shift), >> (right shift)
// ternary operator -> ?

// include method,

// comparison operators always return boolean value

// control flow

//  for loop, while loop, do while loop

// for(let x=0;x<=8;x++){ // step change
//   console.log('I am sunil',x);
// }
//array
let disha = ["Maggie", "Chowmein", "india"];

// // access the array values
// console.log(disha[2]);
// for(let i=0;i<disha.length;i++){ //
//   console.log(disha[0]);
// }
// let i=0;
// while(i<disha.length){
//   console.log(disha[0]);
//   i++;
// }

// let i=0;
// do{
// console.log("Sunil =",i);
// i++;
// }while(i>1);
// console.log(typeof disha)

// // while loop
// // row-> 4, column:5

// for (let row; row<=5; row++){
//   console.log('for loop', row);
// }
//  console.log('*******');

//  let i=1;
// while(i<=5){ // get statement-> conndition is mandatory
// console.log('*', i);
// i++; // if this isnt presnet, then infinite loop occurs.
// }
// let j=0;
// while(j<disha.length){
//   console.log("My favourite dish is = ", disha[j]);
//   j++; // without this, statement will get infinite loop.
// }

// //Do-while loop
// const greeting = (person) => {
//   const name = person ? person.name : "stranger";
//   return `Howdy, ${name}`;
// };

// console.log(greeting({ name: "Alice" })); // "Howdy, Alice"
// console.log(greeting(0)); // "Howdy, stranger"

// q1:
// let arr1=[1,2,3,4,5];
// let arr2=[1,2,3,4,5];
// let sum1 = arr1.reduce((a,b) => a + b);
// let sum2 = arr2.reduce((a,b) => a + b);
// let sum =sum1+sum2;
// console.log("The sum of both arrays are: ", sum);

// // //q2:
// // // let n=prompt("Enter a number:");
// // // for( let i=2;i<=n;i+=2){
// // //   console.log(i);
// // // }

// // let n = 20;

// // for (let i = 2; i <= n; i++) {
// //   let isPrime = true;

// //   for (let j = 2; j < i; j++) {
// //     if (i % j === 0) {
// //       isPrime = false;
// //       break;
// //     }
// //   }

// //   if (isPrime) {
// //     console.log(i);
// //   }
// // }202

// // conditional statements, if-else, switch, ternary operator

// // if-else// nested-if
// // let budget=800;
// // if(budget>600){ // block scope
// //   console.log("Budget is tight");
// // }else if(budg*et>400){
// //   console.log("Budget is thik thak");
// // }else if(budget<200){
// //   console.log("Budget is okay");
// // }else{
// // console.log("Budget is not possible");
// // }
// // console.log("I am sunil");
// // console.log("I am sunil.");

// // break and continue statement -> jump statements
// // for (let k=1;k<=10;k++){
// //   if(k==3){
// //     break;
// //   }
// //   console.log(k);
// // }
// // switch statement
// // let day=4;
// // switch(day){
// //   case 1:  console.log("Monday");
// //  break;
// //     case 2:
// //       console.log("Tuesday");
// //       break;
// //       case 3:
// //         console.log("Wednesday");
// //        break;
// //         case 4:  console.log("Thursday");
// //         break;
// //           case 5:
// //    console.log("Friday");
// //    break;
// //    default:
// //  console.log("Sunday");
// // }

// // ternary operator

// //-->left-riight approch in javascript

// // let menu=12;
// // let weigh=28;
// // if(menu>18){
// //   console.log("Aman");
// // }
// // else{
// //   console.log("sunil");
// // }
// // single line solution
// //  let resul=menu<18?weigh>28? "Qulify" : "Aman":"Sunil"; // tenrary operator
// // console.log(resul);

// // variable and block scope

// // global scope, block scope
// // let d=10;
// // d=20// global scope
// // if(true){
// //  const w=10;
// //  console.log(d);
// // }
// // conditional;l stement &&, ||, !
// // global scope

// // functions

// // revision

//  //=> function or

//  let arr1=[1,2,3,4,5];
//  let arr2=[1,2,3,4,6];

// // reducer function
// let sum1=arr1.reduce((a,b) =>a+b);
// console.log(sum1);
// let sum2=arr2.reduce((a,b) =>a+b);
// let sum= sum1+ sum2;
// console.log(sum);

// //  even no., prime no
// let n=prompt("Enter a no.");// function
// for ( i = 0; i <= n; i++) {
//   if (i % 2 === 0) {
//       console.log(i);
//   }
// }

// let w=18;
// if(w>20){
//   console.log("My age is greater");

// }
//   else{
//     console.log("My age is less");
//   }

// ternary operator
// let name= w>20 ? "My age is greater" : "My age is less";
// console.log(name);

// function

/// some kind od variable holding some data ->some piece of code which we can use in our program many time.

// declaration

// function nameoffunction() {
//   console.log("I am sunil");
// }
// nameoffunction();

// nameoffunction();

// // function expression
// let fun = function () {
//   // anonymous function
//   console.log("I am sunil");
// };

// // calling function expression
// fun();
// // real example

// // passing values(parameters and argunments)
// let invitation = function (name, time = "night") {
//   // parameter-> local variable
//   console.log(`I am ${name}. I sleep at ${time} `);
// };
// invitation("amisha, morning"); // argument
// invitation("sunil");
// invitation();

// // returning statement (how to return value of any function)

// let ageCalculate = function (birthYear, currentYear) {
//   // global scope, blocked scope
//   let age = currentYear - birthYear;
//   return age;
// };
// console.log(ageCalculate(2002, 2023));
// console.log("I am aman ");

// Es6 v/s Es7

//Es6 (Arrow function)

// Special type of function which allows us to write functions more faster bcz ->
// no need of function keyword
// no need of paranthesis() in case of single parameter
// no need to use curley {} statement if single line code is in function
// no need to use return statement if single line code is used infunction

//  let invitatio = function(name){
//   console.log(`Your age is${name}`)
//  }
//   invitatio('aman')

//   // arrow function

//   let invitati = name => `Your name is ${name}`
//   console.log(invitati("aman"))


//   // Passing function as an argument (Higher order function)
//   let upperCase = function(str){
//     return str.toUpperCase(); // 
//   }
//   let lowerCase = function(str){
//     return str.toLowerCase();
//   }  
// let age = function(str,fun){
//   return fun(str)
// }
// console.log(age('hello',upperCase))

// let ag = function(str,fun){
//   return fun(str)
// }
// console.log(ag('hello', lowerCase))

// // function returning another function

// // 1st method 

// let close = function(name){
//   return function(age){
//     console.log(`${name} ${age}`)
//     return true
//   }
// }

// console.log(close("Your name is aman")(18))


// // 2 nd method 

// let closed= close("Your name is aman");
// // closed('Marie')
// console.log(closed)

// closed is a higher order function
// // spread operator

// let fruit1= ['Mango', 'Guava']; 
// let fruit2= ['Orange', 'Papaya'];

// let fruit= [...fruit1, ...fruit2];
// console.log(fruit);
let num= [1,2,3,4,5];

 // for each loop
// num.forEach((element)=>{
//   console.log(element+element);
// })

//Array,from
let name='Harry';
// let arr=Array.from(name);
// console.log(arr);


// for ...of
// for(let i of num){
// console.log(i);
// }

//for ..in
// for(let i in num){
//   console.log(i);
// }

//map
num.map((value)=>{
  console.log(value);
})
console.log(num);