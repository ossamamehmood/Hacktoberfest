'use strict'

class Calculator {

  constructor(number) {
    this.number = number
  }
  add(penambahan) {
    this.number += penambahan
    return this
  }
  subtract(pengurangan) {
    this.number -= pengurangan
    return this
  }
  multiply(perkalian) {
    this.number *= perkalian
    return this
  }
  divide(pembagian) {
    this.number /= pembagian
    return this
  }
  square(pangkat) {
    this.number = Math.pow(this.num, pangkat)
    return this
  }
  squareRoot(akarPangkat) {
    this.number = Math.sqrt(this.number, akarPangkat)
    return this
  }
  piLingkaran() {
    this.number = Math.PI * this.number
    return this
  }
}

/** note : you can use several features from ecmascript, such as:
* - Classes
* - Default Parameters
* - Destructured Assignment
* - Template Literals
* - Method Chaining
*/

module.exports = Calculator