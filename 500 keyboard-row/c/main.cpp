#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> findWords(vector<string>& words) {
  vector<string> r;
  int i = -1, j = 0;
  bool b;
  char t;

  for (string &s : words) {
    i = -1;

    b = true;
    for (char &c : s) {
      t = c;
      if (c >= 'A' && c <= 'Z')
        t += 'a' - 'A';

      switch (t) {
        case 'q':case 'w':case 'e':case 'r':case 't':case 'y':
        case 'u':case 'i':case 'o':case 'p':
          j = 1;
          break;
        case 'a':case 's':case 'd':case 'f':
        case 'g':case 'h':case 'j':case 'k':case 'l':
          j = 2;
          break;
        case 'z':case 'x':case 'c':case 'v':case 'b':
        case 'n':case 'm':
          j = 3;
          break;
        default:
          j = 4;
      }

      if (i == -1) {
        i = j;
      } else if (i != j) {
         b = false;
         break;
      }
    }
    if (b) {
      r.push_back(s);
    }
  }

  return r;
}

int main(void) {
  vector<string> words = {"Hello","Alaska","Dad","Peace"};

  vector<string> nw = findWords(words);
  for (string &w: nw) {
    cout << w << endl;
  }
}
