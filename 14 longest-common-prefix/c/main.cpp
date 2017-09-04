#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string> &strs) {
  if (strs.empty())
    return "";

  string d;
  int i = 1;
  string first = strs.back();
  strs.pop_back();

  for (char &c: first) {
    for (string &s : strs) {
      if (s.size() < i || s[i - 1] != c)
        goto OUT;
    }
    d.push_back(c);
    i++;
  }

  OUT:
  return d;
}

int main(void) {
  vector<string> strs = {"ab", "abby", "absolute"};

  cout << longestCommonPrefix(strs);
}
