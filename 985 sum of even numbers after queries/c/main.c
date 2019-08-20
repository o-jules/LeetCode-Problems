
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumEvenAfterQueries(int* A, int ASize, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    *returnSize = queriesSize;
    *queriesColSize = 2;

    int *answer = malloc(sizeof(int) * queriesSize);
    int sum = 0;
    for (int i = 0; i < ASize; i++) {
        if (A[i] % 2 == 0) {
            sum += A[i];
        }
    }

    int j, k, l;
    for (int i = 0; i < queriesSize; i++) {
        j = queries[i][1];
        k = queries[i][0];
        l = A[j];
        A[j] += k;
        if (l % 2 == 0) {
            if (A[j] % 2 != 0) {
                sum -= l;
            } else {
                sum += k;
            }
        } else {
            if (A[j] % 2 == 0) {
                sum += A[j];
            }
        }
        answer[i] = sum;
    }

    return answer;
}
