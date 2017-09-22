/**
 * Leetcode最优解
 */

int climbStairs(int n) {
    if(n == 1) {
      return 1;
    }

    if(n == 2) {
      return 2;
    }

    int arr[n+1];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;

    int i;
    for(i = 3; i <= n; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }

    return arr[n];
  }

