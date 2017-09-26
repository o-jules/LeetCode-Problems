#include<stdio.h>
#include<limits.h>

int maximumProduct(int* nums, int numsSize) {
  if (numsSize == 3) {
    int p = 1;
    for(int i = 0; i < numsSize; i++) {
      p *= nums[i];
    }
    return p;
  }

  int cpos = 0, cneg = 0;
  int pos[3] = {0, 0, 0};    // 绝对值最大的3个正整
  int neg[2] = {0, 0};       // 绝对值最大的2个负数
  int negMin[3] = {INT_MIN, INT_MIN, INT_MIN}; // 绝对值最小的3个负数

  for(int i = 0; i < numsSize; i++) {
    if (nums[i] >= 0) {
      cpos ++;

      if (nums[i] > pos[0]) {
        pos[2] = pos[1];
        pos[1] = pos[0];
        pos[0] = nums[i];
      } else if (nums[i] > pos[1]) {
        pos[2] = pos[1];
        pos[1] = nums[i];
      } else if (nums[i] > pos[2]) {
        pos[2] = nums[i];
      }
    } else {
      cneg ++;

      if (nums[i] < neg[0]) {
        neg[1] = neg[0];
        neg[0] = nums[i];
      } else if (nums[i] < neg[1]) {
        neg[1] = nums[i];
      }

      if (nums[i] > negMin[0]) {
        negMin[2] = negMin[1];
        negMin[1] = negMin[0];
        negMin[0] = nums[i];
      } else if (nums[i] > negMin[1]) {
        negMin[2] = negMin[1];
        negMin[1] = nums[i];
      } else if(nums[i] > negMin[2]) {
        negMin[2] = nums[i];
      }
    }
  }

  if (cpos == 0) {
    return negMin[0] * negMin[1] * negMin[2];
  }

  int l = neg[0] * neg[1] * pos[0];
  if (cpos <= 2) {
    return l;
  }

  int r = pos[0] * pos[1] * pos[2];
  return l > r ? l : r;
}

void test(int *nums, int size) {
  int p = maximumProduct(nums, size);
  printf("max = %d\n", p);
}

int main(void) {
  // int list[6] = {1,2,3,-4,5,4};
  int list[6] = {-1,-2,-3,-4,-5,-4};
  test(list, 6);
}
