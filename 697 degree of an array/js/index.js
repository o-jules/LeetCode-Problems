/**
 * @param {number[]} nums
 * @return {number}
 */
var findShortestSubArray = function(nums) {
  const countMap = {};
  let degree = 1;

  nums.forEach((n, i) => {
    const item = countMap[n];
    if (item) {
      item.count++;
      item.end = i;
      if (degree < item.count) {
        degree = item.count;
      }
    } else {
      countMap[n] = {
        count: 1,
        start: i - 1,
        end: i
      };
    }
  });

  if (degree === 1) {
    return 1;
  }

  let min = Infinity;
  Object.keys(countMap).forEach(key => {
    const item = countMap[key]
    if (item.count === degree) {
      const len = item.end - item.start
      if (min > len) {
        min = len;
      }
    }
  });

  return min;
};

console.log(findShortestSubArray([1, 2, 2, 3, 1, 4, 2]));
