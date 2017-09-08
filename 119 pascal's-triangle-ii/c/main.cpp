#include <iostream>
#include <vector>

using namespace std;

// 数学法
/*
vector<int> getRow(int rowIndex) {
  if (rowIndex <= 0)
    return {1};

  vector<int> r(rowIndex, 1);
  if (rowIndex <= 2)
    return r;

  int mid = rowIndex/2 + (rowIndex%2 ? 1 : 0);
  for (int i = 1; i <= mid; i++) {
    r[i] = r[rowIndex - i] = //;
  }

  return r;
}
*/

// 迭代法
vector<int> getRow(int rowIndex) {
  if (rowIndex <= 0)
    return { 1 };

  int count = rowIndex + 1;
  vector<int> r(count, 1);

  int prev, tmp;
  for (int j = 1; j <= count; j++) {
    prev = 1;
    for (int i = 1; i < (j/2 + j%2); i++) {
      tmp = r[i];
      r[i] = r[j - i - 1] = (r[i] + prev);
      prev = tmp;
    }
  }

  return r;
}

int main(void) {
  vector<int> v = getRow(2);
  for (int &i: v) {
    cout << i << " ";
  }
  cout << endl;
}
