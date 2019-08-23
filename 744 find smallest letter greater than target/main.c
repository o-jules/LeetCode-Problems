
char nextGreatestLetter(char* letters, int lettersSize, char target){
  char c;
  for (char i = target + 1; i < target + 26; i++) {
    c = i > 'z' ? i - 26 : i;
    for (int j = 0; j < lettersSize; j++) {
      if (c == letters[j]) {
        return c;
      }
    }
  }

  return target;
}
