

const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Masukkan angka maksimum: ', (input) => {


  const maxNumber = parseInt(input);
  let total = 0;

 

  for (let i = 1; i <= maxNumber; i++) {
    if (i % 2 === 0) {
      total += i;
    }
  }



  console.log(`Jumlah bilangan genap dari 1 hingga ${maxNumber} adalah: ${total}`);


  rl.close();
});
