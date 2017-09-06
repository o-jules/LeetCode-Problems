#include <string>

using namespace std;

string addBinary(string a, string b) {
  string s;
  int c = 0, r = 0;
  int ia = a.size() - 1, ib = b.size() - 1;

  while(ia >= 0 || ib >= 0) {
    c = 0;
    if (ia >= 0 && a[ia] == '1') {
      c++;
    }
    if (ib >= 0 && b[ib] == '1') {
      c++;
    }

    r += c;
    s.insert(0, 1, r % 2 == 0 ? '0': '1');
    r = r < 2 ? 0 : 1;

    ia --;
    ib --;
  }

  if (r != 0) {
    s.insert(0, 1, '1');
  }

  return s;
}
