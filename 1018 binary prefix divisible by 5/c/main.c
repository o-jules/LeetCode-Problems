
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* prefixesDivBy5(int* A, int ASize, int* returnSize){
    *returnSize = ASize;
    bool *res = (bool *)calloc(ASize, sizeof(bool));

    int q0 = 0, q1 = 1, q2 = 2, q3 = 3, q4 = 4;
    int DFA[5][2] = {
        {q0, q1},
        {q2, q3},
        {q4, q0},
        {q1, q2},
        {q3, q4}
    };

    int status = q0;
    for (int i = 0; i < ASize; i++) {
        int d = A[i];
        // for the DFA, see:
        // https://www.quora.com/How-do-i-check-if-a-binary-number-is-divisible-by-say-n
        // https://stackoverflow.com/questions/21897554/design-dfa-accepting-binary-strings-divisible-by-a-number-n
        status = DFA[status][d];
        res[i] = status == q0;
    }

    return res;
}
