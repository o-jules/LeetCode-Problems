/**
 * Leetcode上的最优解
 * 注意优化的部分
 */

/**
 * @param {number[][]} wall
 * @return {number}
 */
var leastBricks = function(wall) {
  var hash = Object.create(null);

  for (var row of wall) {
      var x = 0;
      for (var i = 0; i < row.length - 1; ++i) {
        x += row[i];
        hash[x] = (hash[x] || 0) + 1;
      }
  }

  var maxEdge = Math.max.apply(Math, Object.values(hash));
  if (maxEdge === -1/0) {
      return wall.length;
  }
  return wall.length - maxEdge;
};
