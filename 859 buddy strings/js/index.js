/**
 * @param {string} A
 * @param {string} B
 * @return {boolean}
 */
var buddyStrings = function(A, B) {
  let lenA = A.length;
  let lenB = B.length;

  if (lenA !== lenB || lenA <= 1) {
    return false;
  }

  const diffPos = [];
  const countMap = {};
  let hasRepeatLetter = false;

  for (let i = 0; i < lenA; i++) {
    if (A[i] !== B[i]) {
      diffPos.push(i);
    }
    if (diffPos.length >= 3) {
      return false;
    }

    if (!hasRepeatLetter) {
      if (countMap[A[i]]) {
        countMap[A[i]]++;
        if (countMap[A[i]] >= 2) {
          hasRepeatLetter = true;
        }
      } else {
        countMap[A[i]] = 1;
      }
    }

  }

  const diffCount = diffPos.length;
  return (diffCount === 0 && hasRepeatLetter) || (diffCount === 2 && A[diffPos[0]] === B[diffPos[1]] && A[diffPos[1]] === B[diffPos[0]]);
};

console.log(buddyStrings("aabb", "baab"));

console.log(buddyStrings("ab", "ab"));

console.log(buddyStrings("aa", "aa"));

console.log(buddyStrings("acab", "abcd"));
