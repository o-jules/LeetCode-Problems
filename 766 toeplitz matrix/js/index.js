/**
 * @param {number[][]} matrix
 * @return {boolean}
 */
var isToeplitzMatrix = function(matrix) {
  let x = matrix.length;
  if (x <= 0) {
    return true;
  }
  let y = matrix[0].length;

  // x range
  for (let i = 0; i < x; i ++) {
    let ix = i, iy = 0;
    let val = matrix[ix][iy];
    while(true) {
      ix ++; iy ++;
      if (ix >= x || iy >= y) break;
      if (matrix[ix][iy] !== val) return false;
    }
  }

  // y range
  for (let i = 1; i < y; i ++) {
    let ix = 0, iy = i;
    let val = matrix[ix][iy];
    while(true) {
      ix ++; iy ++;
      if (ix >= x || iy >= y) break;
      if (matrix[ix][iy] !== val) return false;
    }
  }
  return true;
};
