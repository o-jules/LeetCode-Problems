/**
 * Leetcode上的最优解
 *
 * 使用循环的解法
 * 比使用递归更快
 */
string read(string s) {
  string res;
  for (int i = 0; i<s.size(); i++) {
    char c = s[i];
    int n = 1;
    while (i + 1<s.size() && s[i + 1] == s[i]) {
      n++; i++;
    }
    res += ((char)(n + '0'));
    res += c;
  }
  return res;
}

string countAndSay(int n) {
  string res = "1";
  while (--n) {
    res = read(res);
  }
  return res;
}
