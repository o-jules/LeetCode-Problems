#include<stdio.h>

#define MAX(l, r) (((l) > (r))? (l): (r))

int maxProfit(int* prices, int pricesSize) {
  int profit = 0;

  int len = pricesSize;
  int tmp;
  if(len >= 1) {
    for(int i = 0; i < len - 1; i++) {
      for (int j = i + 1; j < len; j++) {
        tmp = prices[j] - prices[i];
        if (tmp > 0) {
          profit = MAX(tmp, profit);
        }
      }
    }
  }

  return profit;
}

void test(int *p, int c) {
  printf("max = %d\n", maxProfit(p, c));
}

int main(void) {
  int a[] = {1, 2};
  test(a, 2);
}
