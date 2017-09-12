#include<iostream>
#include<vector>

using namespace std;

void rotate(vector<int> &nums, int k) {
  int size = nums.size();
  if (size <= 1 || k == 0) return;
  k = k % size;
  if (k) {
    int tmp;
    while (k--) {
      tmp = nums.back();
      nums.pop_back();
      nums.insert(nums.begin(), 1, tmp);
    }
  }
}

void test(int c, int n) {
  vector<int> v;
  for (int j = 0; j < c; j++) {
    v.push_back(j+1);
  }

  cout << "before: [ ";
  for (auto &i: v) {
    cout << i << " ";
  }
  cout << "]" << endl;

  rotate(v, n);

  cout << "after:  [ ";
  for (int &i: v) {
    cout << i << " ";
  }
  cout << "]" << endl;
}

int main(void) {
  test(2, 1);
}
