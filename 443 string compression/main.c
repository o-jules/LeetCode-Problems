
int compress(char* chars, int charsSize){
  if (charsSize <= 1) {
    return charsSize;
  }

  char c = chars[0], swap;
  int i = 1, j = 0, acc = 1; // accummulation
  int l, r;
  // scan next
  while (i <= charsSize && j < charsSize) {
    // attention!!
    // `i != charsSize` is needed as chars is not a string (with '/0' at the end)
    //  but rather a char array in LeetCode test cases.
    if (i < charsSize && c == chars[i]) {
      acc++;
      i++;
    } else {
      chars[j++] = c;
      if (acc > 1) {
        l = r = j;
        while (acc > 0) {
          r = j;
          chars[j++] = '0' + (acc % 10);
          acc /= 10;
        }

        while (l < r) {
          swap = chars[l];
          chars[l++] = chars[r];
          chars[r--] = swap;
        }
      }
      if (i < charsSize) {
        c = chars[i];
        acc = 1;
      }
      i++;
    }
  }

  return j;
}
