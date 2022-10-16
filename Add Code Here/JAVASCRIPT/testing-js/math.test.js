const { suma, multipli, divide } = require('./math.js');

//code to check basic functions with the help of javascript jest

test("Se coloca el mensaje como ejemplo adds 1 + 3 slould be 4", () => {
    const resulta = suma(1, 3);
    expect(resulta).toBe(4)
})

test("Testing de la funcion de multiplicar", () => {
    const resulta = multipli(8, 3);
    expect(resulta).toBe(24)
})

test("Testing de la funcion de dividir ", () => {
    const resulta = divide(10, 5);
    expect(resulta).toBe(2)
})

test("Funcion con error de testing", () => {
    const resulta = suma(3, 1);
    expect(resulta).toBe(6)
})