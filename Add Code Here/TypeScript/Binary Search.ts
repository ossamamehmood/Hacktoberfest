function binary_search(x: number[], f: number): void {
  let l: number = 0;
  let h: number = x.length - 1;
  let flag: boolean = false;

  while (l < h) {
    let mid: number = Math.floor((l + h) / 2);
    if (x[mid] === f) {
      flag = true;
      break;
    } else {
      if (x[mid] < f) {
        l = mid + 1;
      } else if (x[mid] > f) {
        h = mid - 1;
      }
    }
  }

  if (flag) {
    console.log(f + ' has been found!');
  } else {
    console.log(f + ' is not found!');
  }
}

const arr: number[] = [1, 3, 5, 6, 7, 77, 88, 99];
const find: number = 1;
binary_search(arr, find);
