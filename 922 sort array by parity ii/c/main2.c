

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* A, int ASize, int* returnSize){
    *returnSize = ASize;

    int *sortedArray = (int *) malloc(sizeof(int) * ASize);
    int ind[2] = {0, 1};
    int r = 0;
    for (int i = 0; i < ASize; i++) {
        r = A[i] % 2;
        sortedArray[ind[r]] = A[i];
        ind[r] += 2;
    }
    return sortedArray;
}

