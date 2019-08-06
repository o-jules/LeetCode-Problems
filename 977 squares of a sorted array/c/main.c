
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* A, int ASize, int* returnSize){
    *returnSize = ASize;
    int *returnA = (int *)malloc(sizeof(int) * ASize);

    // find the depart
    int j = 0;
    int type = A[0] < 0 ? 0 : 2; // 0 all negative, 1 negative + postive, 2 all positive
    if (type == 0) {
        for (int i = 0; i < ASize; i++) {
            if (A[i] >= 0) {
                type = 1;
                j = i;
                break;
            }
        }
    }

    if (type == 0) {
        // all negative
        for (int i = 0; i < ASize; i++) {
            returnA[i] = A[ASize - 1 - i] * A[ASize - 1 - i];
        }
    } else if (type == 2) {
        // all positive
        for (int i = 0; i < ASize; i++) {
            returnA[i] = A[i] * A[i];
        }
    } else {
        // before j, all negative
        int l = j - 1, r = j;
        int i = 0, k = 0;
        while (l >= 0 && r < ASize) {
            if (A[l] + A[r] >= 0) {
                k = A[l--];
            } else {
                k = A[r++];
            }
            returnA[i++] = k * k;
        }
        while (l >= 0) {
            k = A[l--];
            returnA[i++] = k * k;
        }
        while (r < ASize) {
            k = A[r++];
            returnA[i++] = k * k;
        }
    }

    return returnA;
}
