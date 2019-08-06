
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* A, int ASize, int* returnSize){
    *returnSize = ASize;
    int *returnA = (int *)malloc(sizeof(int) * ASize);
    int l = 0, r = ASize - 1;
    int i = A[l] * A[l], j = A[r] * A[r], k = ASize - 1;
    while (l <= r) {
      if (i > j) {
        returnA[k--] = i;
        l++;
        if (l < ASize) {
          i = A[l] * A[l];
        }
      } else {
        returnA[k--] = j;
        r--;
        if (r >= 0) {
          j = A[r] * A[r];
        }
      }
    }
    return returnA;
}
