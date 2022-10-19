var rotate = function (matrix) {
    let n=[]
    
  for (i = 0; i < matrix.length; i++) {
    for (j = 0; j < matrix.length; j++) {
      console.log(matrix[i][j], "\r");
    }
  }
  return matrix;
};

console.log(
  rotate([
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
  ])
);
