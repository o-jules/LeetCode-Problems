

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    *returnSize = 2;
    int k = 0;
    int *returnA = (int *)malloc(sizeof(int) * 2);
    for (int i = 0; i < numbersSize; i++) {
        k = target - numbers[i];

        // optimzation: search algorithm
        // binary search will simply do good
        for (int j = i + 1; j < numbersSize; j++) {
            if (numbers[j] == k) {
                *returnA = i + 1;
                *(returnA + 1) = j + 1;
                return returnA;
            }
            if (numbers[j] > k) {
                break;
            }
        }
    }
    // well, no answer
    return returnA;
}


