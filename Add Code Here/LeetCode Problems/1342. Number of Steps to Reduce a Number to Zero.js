let numberOfSteps = function (num) {
  let step = 0;

  while (num !== 0) {
    num % 2 === 0 ? (num /= 2) : num--;
    step++;
  }
  return step;
};
