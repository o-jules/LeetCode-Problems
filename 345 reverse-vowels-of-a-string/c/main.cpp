#include<iostream>
#include<string>

using namespace std;

#define IS_VOWEL(c) (\
  c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || \
  c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')

string reverseVowels(string s) {
  string n = string(s);
  int r = n.size() - 1, l = 0;

  char tmp;
  while (true) {
    while (!(IS_VOWEL(n[l]) || l > 1 + r)) {
      l++;
    }
    if(l > 1 + r) break;

    while (!(IS_VOWEL(n[r]) || l > 1 + r)) {
      r--;
    }
    if(l > 1 + r) break;

    tmp = n[l]; n[l] = n[r]; n[r] = tmp;
    l++; r--;
    if(l >= 1 + r) break;
  }

  return n;
}

int main(void) {
  // reverseVowels("ai");

  cout << reverseVowels("ai") << endl;
  /*
  cout << reverseVowels("") << endl;
  cout << reverseVowels("e") << endl;
  cout << reverseVowels("h") << endl;
  cout << reverseVowels("he") << endl;
  cout << reverseVowels("eh") << endl;
  cout << reverseVowels("hello") << endl;
  cout << reverseVowels("Leetcode") << endl;
  */
}
