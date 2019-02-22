function isLetter(x) {
  return (x >= 97 && x <= 122) || (x >= 65 && x <= 90);
}


/**
 * @param {string} S
 * @return {string}
 */
var reverseOnlyLetters = function(S) {
  let size = S.length;
  let newStr = S.split('');

  let l = 0, r = size - 1;
  let isL = false, isR = false;

  while (l <= r) {
    isL = isLetter(S.charCodeAt(l));
    isR = isLetter(S.charCodeAt(r));
    if (isL && isR) {
      newStr[r] = S[l];
      newStr[l] = S[r];
      l++;
      r--;
    } else {
      if (!isL) {
        newStr[l] = S[l];
        l++;
      }
      if (!isR) {
        newStr[r] = S[r];
        r--;
      }
    }
  }

  return newStr.join('');
};


console.log(
  reverseOnlyLetters("ab-cd")
)
