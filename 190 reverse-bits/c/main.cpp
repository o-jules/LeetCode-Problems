#include <iostream>
#include <cstdint>

using namespace std;

uint32_t reverseBits(uint32_t n) {
  if (n == 0)
    return n;

  uint32_t i = 0;
  uint32_t d = 1 << 31;
  while (n) {
    if (n & 1) i |= d;
    n >>= 1;
    d >>= 1;
  }

  return i;
}

void test(uint32_t n) {
  cout << "rev(" << n << ") = ";
  cout << reverseBits(n);
  cout << endl;
}

int main(void)
{
  test(43261596);
  return 0;
}
