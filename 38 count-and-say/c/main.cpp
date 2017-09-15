#include<iostream>
#include<string>

using namespace std;

string countAndSay(int n) {
  if (n < 1) return "";
  if (n == 1) return "1";

  string prev = countAndSay(n - 1);
  string s = "";
  int count = 0;
  char t = 0;

  for (char &c: prev) {
    if (t == c) {
      count ++;
    } else {
      if (t) {
        s += to_string(count) + t;
      }
      t = c;
      count = 1;
    }
  }
  s += to_string(count) + t;

  return s;
}

void test(int n) {
  cout << n << "th is: "<< countAndSay(n) << endl;
}

int main(void) {
  test(1);
  test(2);

  test(3);
  test(4);
  test(5);
  test(6);
  test(7);
  test(8);
  test(9);
  test(10);
}
