#include<iostream>
#include<vector>

using namespace std;

vector<int> plusOne(vector<int> &digits) {
  int i = digits.size() - 1;
  if (i < 0)
    return {1};

  vector<int> res;
  int j = 0,
      f = 1;
  for (; i >= 0; i--) {
    j = digits[i] + f;
    f = j/10;
    j %= 10;
    res.insert(res.begin(), 1, j);
  }

  if (f != 0)
    res.insert(res.begin(), 1, f);

  return res;
}

int main(void) {
  vector<int> digits = {9,9,9};

  vector<int> num = plusOne(digits);
  for (int &i: num) {
    cout << i << " ";
  }
  cout << endl;
}
