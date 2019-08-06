#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    *returnSize = 2;
    int k, l, m, r = 0;
    int *returnA = (int *)malloc(sizeof(int) * 2);
    for (int i = 0; i < numbersSize; i++) {
        k = target - numbers[i];

        // optimzation: search algorithm
        // binary search will simply do good
        for (int j = i + 1; j < numbersSize; j++) {
            // search from `j` to `numberSize`;
            l = j, r = numbersSize - 1;
            while (l < r) {
              m = l + (r - l) / 2;
              if (numbers[m] > k) {
                r = m;
              } else if (numbers[m] < k) {
                l = m + 1;
              } else {
                *returnA = i + 1;
                *(returnA + 1) = m + 1;
                return returnA;
              }
            }
        }
    }
    // well, no answer
    return returnA;
}

int main() {
  int *size = (int *)malloc(sizeof(int));
  int *ar;

  int a1[7] = { 3,24,50,79,88,150,345 };
  int t1 = 200;
  ar = twoSum(a1, 7, t1, size);
  printf("[%d, %d]\n", ar[0], ar[1]);

  int a2[7] = { 2,3,4 };
  int t2 = 6;
  ar = twoSum(a2, 7, t2, size);
  printf("[%d, %d]\n", ar[0], ar[1]);

  free(size);
  return 0;
}
