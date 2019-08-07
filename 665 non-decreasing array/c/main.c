
/**
 * 注意边界：
 * 第一次遇见反例时，其相邻不能同时都是反例
 */
bool checkPossibility(int* nums, int numsSize){
    int antiCount = 0;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i - 1] > nums[i]) {
            if (antiCount == 1) {
              return false;
            }
            if ((i + 1 < numsSize && nums[i + 1] < nums[i - 1]) &&
                (i - 2 >= 0 && nums[i] < nums[i - 2])) {
              return false;
            }
            antiCount++;
        }
    }

    return antiCount <= 1;
}
