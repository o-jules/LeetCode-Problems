#include<stdio.h>
#include<vector>

bool isPalindrome(int x) {
  if (x == 0)
    return true;

  if (x < 0) {
    // x = -x;
    // Leetcode要求负数为false
    return false;
  }

  std::vector<int> list;
  while (x) {
    list.push_back(x % 10);
    x /= 10;
  }
  int j = list.size() - 1;
  int i = 0;

  while (i < j) {
    if (list[i] != list[j]) {
      return false;
    }
    i++;
    j--;
  }

  return true;
}

int main(void) {
  if (isPalindrome(121)) {
    printf("yes!\n");
  }

  if (isPalindrome(-12421)) {
    printf("yes!\n");
  }

  if (isPalindrome(-2147483648)) {
    printf("yes!\n");
  }

  // overflow test:
  if (isPalindrome(-2147447412)) {
    printf("yes!\n");
  }
}
