
function getDigit(t) {
  let count = 0;
  while(t) {
    if (t & 1) count++;
    t = t >> 1
  };
  return count;
}

// 4
const hours =(function() {
  const hoursMap = new Array(4);
  let c = 0;
  for (let i = 0; i < 12; i++) {
    c = getDigit(i);
    if (hoursMap[c]) {
      hoursMap[c].push('' + i);
    } else {
      hoursMap[c] = ['' + i];
    }
  }
  return hoursMap;
})();

// 6
const minutes = (function() {
  const minutesMap = new Array(6);

  let c = 0;
  for (let i = 0; i < 60; i++) {
    c = getDigit(i);
    if (minutesMap[c]) {
      minutesMap[c].push(i >= 10 ? '' + i : '0' + i);
    } else {
      minutesMap[c] = [i >= 10 ? '' + i : '0' + i];
    }
  }
  return minutesMap;
})();

/**
 * @param {number} num
 * @return {string[]}
 */
var readBinaryWatch = function(num) {
    if (num >= 10 || num < 0) {
      return []
    }

    const list = []
    let i = 0, j = num;
    while (i < 4 && j >= 0) {
      if (j >= 6) {
        i++; j--; continue;
      }
      hours[i].forEach(i => {
        minutes[j].forEach(j => {
          list.push(i + ':' + j)
        })
      })
      i++; j--;
    }

    return list;
};

// console.log(readBinaryWatch(0))
// console.log(readBinaryWatch(1))
console.log(readBinaryWatch(6).length)
