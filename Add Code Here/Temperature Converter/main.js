const celsiusInput = document.querySelector('#celsius > input');
const fahrenheitInput = document.querySelector('#fahrenheit > input');
const kelvinInput = document.querySelector('#kelvin > input');

const roundToTwoDP = (num) => {
  return num.toFixed(2);
};


const celsiusToFaAndKe = () => {
  const celsiusTemp = parseFloat(celsiusInput.value);
  const fahrenheitTemp = (celsiusTemp * 1.8) + 32;
  const kelvinTemp = celsiusTemp + 273.15;

  fahrenheitInput.value = roundToTwoDP(fahrenheitTemp);
  kelvinInput.value = roundToTwoDP(kelvinTemp);
};


const fahrenheitToCeAndKe = () => {
  const fahrenheitTemp = parseFloat(fahrenheitInput.value);
  const celsiusTemp = (fahrenheitTemp - 32) * (5 / 9);
  const kelvinTemp = (fahrenheitTemp + 459.67) * (5 / 9);

  celsiusInput.value = roundToTwoDP(celsiusTemp);
  kelvinInput.value = roundToTwoDP(kelvinTemp);
};

const kelvinToCeAndFa = () => {
  const kelvinTemp = parseFloat(kelvinInput.value);
  const celsiusTemp = kelvinTemp - 273;
  const fahrenheitTemp =  1.8 * (kelvinTemp - 273) + 32;

  celsiusInput.value = roundToTwoDP(celsiusTemp);
  fahrenheitInput.value = roundToTwoDP(fahrenheitTemp);
};


const main = () => {
  celsiusInput.addEventListener('input', celsiusToFaAndKe);
  fahrenheitInput.addEventListener('input', fahrenheitToCeAndKe);
  kelvinInput.addEventListener('input', kelvinToCeAndFa);
};

main();