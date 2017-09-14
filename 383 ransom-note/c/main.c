
bool canConstruct(char* ransomNote, char* magazine) {
  int table[26] = {0};
  // memset(table, 0, 26);

  int l = strlen(magazine);
  while (l--) {
    table[magazine[l] - 'a'] ++;
  }

  l = strlen(ransomNote);
  while(l--) {
    if (table[ransomNote[l] - 'a'] > 0) {
      table[ransomNote[l] - 'a'] --;
    } else {
      return false;
    }
  }

  return true;
}
