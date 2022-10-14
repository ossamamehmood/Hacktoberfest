/**
 * a closure is a function that references variables 
 * in the outer scope from its inner scope. 
 * The closure preserves the outer scope inside its inner scope.
 */

function greeting(message) {

    return function (name) {

        return message + ' ' + name
    }

}

let sayHi = greeting('Hi')
let sayHello = greeting('Hello')

console.log(sayHi('John'))
console.log(sayHello('John'))