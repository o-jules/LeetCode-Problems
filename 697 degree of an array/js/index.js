/**
 * @param {number[]} nums
 * @return {number}
 */
var findShortestSubArray = function(nums) {
  const countMap = {};

  for (let i = 0; i < nums.length; i++) {
    const n = nums[i];
    if (countMap[n]) {
      countMap[n].count ++;
      countMap[n].end = i;
    } else {
      countMap[n] = {
        count: 1,
        start: i - 1,
        end: i
      }
    }
  }

  const sort = Object.keys(countMap).map(i =>  countMap[i]).sort((l,r) => r.count - l.count);
  const degree = sort[0].count
  if (degree === 1) {
    return 1
  }

  const countList = sort.filter(i => i.count === degree).map(i => i.end - i.start);
  return Math.min(...countList);
};

console.log(
  findShortestSubArray([1,2,2,3,1,4,2])
)
