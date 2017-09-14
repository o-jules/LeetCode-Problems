#include<iostream>
#include<vector>

using namespace std;

int searchInsert(vector<int> &nums, int target) {
  int l = 0, r = nums.size() - 1;
  int i;

  while (l <= r) {
    i = l + (r - l)/2;

    if (target == nums[i])  return i;

    if (target > nums[i]) {
      l = i + 1;
    } else {
      r = i - 1;
    }

  }

  return l;
}

void test(vector<int> &n, int t) {
  int j = searchInsert(n, t);
  cout << "insert at " << j << endl;
}

int main(void) {
  vector<int> v = {1, 3, 5, 6};

  test(v, 5); // 2
  test(v, 2); // 1
  test(v, 7); // 4
  test(v, 0); // 0

  return 0;
}
