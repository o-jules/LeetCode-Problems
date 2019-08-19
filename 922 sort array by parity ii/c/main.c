

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* A, int ASize, int* returnSize){
    *returnSize = ASize;

    int *sortedArray = (int *) malloc(sizeof(int) * ASize);
    int indexes[2] = { 0, 0 };
    int r = 0;
    for (int i = 0; i < ASize; i++) {
        r = i % 2;
        while (indexes[r] < ASize) {
            if (A[indexes[r]] % 2 == r) {
                sortedArray[i] = A[indexes[r]++];
                break;
            }
            indexes[r]++;
        }
    }
    return sortedArray;
}
