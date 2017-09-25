#include <iostream>
#include <unordered_set>

using namespace std;

bool isHappy(int n) {
  if (n <= 0)
    return false;

  unordered_set<int> cache;
  int sum = 0, i = 0;

  while (n != 1) {
    sum = 0;
    while (n >= 10) {
      i = n % 10;
      sum += i * i;
      n = n/10;
    }
    sum += n * n;

    if (!cache.empty() && cache.find(sum) != cache.end()) {
      return false;
    } else {
      cache.insert(sum);
    }

    n = sum;
  }

  return true;
}



void test(int n) {
  cout << n << (isHappy(n) ? " happy" : " sad") << endl;
}

int main(void) {
  test(19);

  return 0;
}
