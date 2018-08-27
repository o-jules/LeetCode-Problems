function findPairs(arr, k) {
  if (k < 0) return 0;

  let obj = {};
  let seen = {};
  let counter = 0;

  for (let i = 0; i < arr.length; i++) {
    let num = arr[i];
    obj[num] = i;
  }

  for (let i = 0; i < arr.length; i++) {
    let num = arr[i];
    let partnerNum = num + k;
    if (obj.hasOwnProperty(partnerNum) && !seen[partnerNum] && obj[partnerNum] !== i) {
      counter++;
      seen[partnerNum] = true;
    }
  }

  return counter;
}
