/**
 * @param {number[][]} A
 * @return {number[][]}
 */
var flipAndInvertImage = function(A) {
  const rowNum = A.length;
  if (rowNum <= 0) {
    return [];
  }

  const colNum = A[0].length;
  const halfCol = Math.floor(colNum / 2);
  const flip = new Array(rowNum);

  for (let i = 0; i < rowNum; i++) {
    let row = new Array(colNum);
    for (let j = 0; j <= halfCol; j++) {
      row[j] = A[i][colNum - j - 1] === 1 ? 0 : 1;
      row[colNum - j - 1] = A[i][j] === 1 ? 0 : 1;
    }
    flip[i] = row;
  }
  return flip;
};

console.log(flipAndInvertImage([[0]]));
console.log(flipAndInvertImage([[1, 1]]));
console.log(flipAndInvertImage([[0, 0, 1]]));
console.log(flipAndInvertImage([[1, 0, 0, 1]]));
console.log(flipAndInvertImage([[1, 0, 0, 1], [0,1,0,1]]));


