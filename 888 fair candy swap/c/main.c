

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fairCandySwap(int* A, int ASize, int* B, int BSize, int* returnSize){
    *returnSize = 2;

    int *res = (int *)calloc(2, sizeof(int));
    int countA = 0, countB = 0;
    int i = 0, j = 0;
    for (i = 0; i < ASize; i++) {
        countA += A[i];
    }
    for (j = 0; j < BSize; j++) {
        countB += B[j];
    }
    if (countA == countB) {
        return res;
    }

    int average = (countA + countB) / 2;
    int padA = average - countA;
    int record[100001] = { 0 };
    for (i = 0; i < ASize; i++) {
        int k = A[i] + padA;
        if (k >= 0 && k <= 100000) {
            record[k] = 1;
        }
    }
    for (j = 0; j < BSize; j++) {
        if (record[B[j]]) {
            res[0] = B[j] - average + countA;
            res[1] = B[j];
        }
    }
    return res;
}
