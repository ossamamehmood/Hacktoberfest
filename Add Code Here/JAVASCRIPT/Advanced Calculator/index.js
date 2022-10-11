'use strict'

const Calculator = require("./calculator.js")

// execute calculator.js here

let perhitunganCalculator = new Calculator(10)
console.log(perhitunganCalculator.add(5).subtract(2).multiply(10).divide(2))