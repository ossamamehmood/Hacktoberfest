function fibonacciRecursive(n) {
  if (n <= 0) return [];
  if (n === 1) return [0];
  if (n === 2) return [0, 1];

  const series = fibonacciRecursive(n - 1);
  series.push(series[series.length - 1] + series[series.length - 2]);
  return series;
}

const n = 10; // Change this value to the desired length of the Fibonacci series
const fibonacciSeries = fibonacciRecursive(n);
console.log(fibonacciSeries);
