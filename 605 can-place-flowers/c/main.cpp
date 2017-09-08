#include <iostream>
#include <vector>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
  if (n == 0)
    return true;

  int count = flowerbed.size();
  int i = 0;
  while (i < count) {
    if (flowerbed[i] == 0) {
      if ((i - 1 < 0 || flowerbed[i - 1] == 0) &&
          (i + 1 >= count || flowerbed[i + 1] == 0)) {
        n--;
        if (n == 0) return true;

        i++;
      }
    }
    i++;
  }

  return false;
}

void test(vector<int> f, int n) {
  cout << (
    canPlaceFlowers(f, n) ?
    "yes!" :
    "no!"
  ) << endl;
}

int main(void) {
  test({1, 0, 0, 0, 1}, 1);
  test({1, 0, 0, 0, 1}, 2);
}
