/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
  var intersect = [];
  for (let i = 0; i < nums1.length; i++) {
    for(let j = 0; j < nums2.length; j++) {
      if (nums1[i] === nums2[j]) {
        addIfNotExist(intersect, nums1[i]);
        break;
      }
    }
  }

  return intersect;
};

function addIfNotExist(list, item) {
  for (let i = 0; i < list.length; i++) {
    if (list[i] === item) {
      return;
    }
  }
  list.push(item);
}

console.log(
  intersection([3,1,2,2,1], [0,-1,2,2,3])
)
