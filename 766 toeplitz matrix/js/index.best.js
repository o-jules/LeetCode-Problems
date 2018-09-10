/**
 * @param {number[][]} matrix
 * @return {boolean}
 */
var isToeplitzMatrix = function(matrix) {
  let x = matrix.length;
  if (x <= 0) return true;
  let y = matrix[0].length;
  if (y <= 0) return true;

  for (let i = 0; i < x; i ++) {
    for (let j = 0; j < y; j++) {
      if (i > 0 && j > 0 && matrix[i - 1][j - 1] !== matrix[i][j]) {
        return false;
      }
    }
  }
  return true;
};
