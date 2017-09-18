/**
 * @param {number[][]} wall
 * @return {number}
 */
var leastBricks = function(wall) {
  const cache = {};
  const key = [];
  const rows = wall.length;

  for (let i = 0; i < rows; i++) {
    const row = wall[i];
    let s = 0;
    for (let j = 0; j < row.length - 1; j++) {
      s += row[j];
      if (cache[s]) {
        cache[s] ++;
      } else {
        cache[s] = 1;
        key.push(s);
      }
    }
  }

  let max = 0;
  let tmp;
  for (let i = 0; i < key.length; i++) {
    tmp = cache[key[i]];
    if (tmp > max) max = tmp;
  }

  return rows - max;
};

// test
const wall = [[1,2,2,1],
[3,1,2],
[1,3,2],
[2,4],
[3,1,2],
[1,3,1,1]];

console.log(leastBricks(wall));
