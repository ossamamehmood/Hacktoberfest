
let result= document.getElementById("result")

function add()
{
    let num1 = document.getElementById("num1").value
    let num2 = document.getElementById("num2").value
result.textContent = parseInt(num1) + parseInt(num2)
}
function subtract()
{
    let num1 = document.getElementById("num1").value
    let num2 = document.getElementById("num2").value
result.textContent = parseInt(num1) - parseInt(num2)
}
function divide()
{
    let num1 = document.getElementById("num1").value
    let num2 = document.getElementById("num2").value
result.textContent = parseInt(num1) / parseInt(num2)
}
function multiply()
{
    let num1 = document.getElementById("num1").value
    let num2 = document.getElementById("num2").value
result.textContent = parseInt(num1) * parseInt(num2)
}
