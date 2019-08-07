

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    int *returnA = (int *)malloc(sizeof(int) * ASize);
    int l = 0, r = ASize - 1;
    for (int i = 0; i < ASize; i++) {
        if (A[i] % 2) {
            returnA[r--] = A[i];
        } else {
            returnA[l++] = A[i];
        }
    }

    *returnSize = ASize;
    return returnA;
}
