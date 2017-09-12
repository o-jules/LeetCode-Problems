#include<limits.h>

/**
 * 最优解法
 * 不断更换最低潮值，并不断更新当前能获得的最大的利润值
 */

int maxProfit(int* prices, int pricesSize) {
  int profit = 0;
  int minprice = INT_MAX;
  int maxprofit = 0;

  for (int i = 0; i < pricesSize; i++) {
    if (prices[i] < minprice) {
      minprice = prices[i];
    }
    else if (prices[i] - minprice > maxprofit) {
      maxprofit = prices[i] - minprice;
    }
  }
  return maxprofit;
}
