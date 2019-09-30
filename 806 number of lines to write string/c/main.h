

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char * S, int* returnSize){
    *returnSize = 2;
    int *res = (int *) calloc(2, sizeof(int));

    int len = strlen(S);
    int c = 0, w = 0;
    for (int i = 0; i < len; i++) {
        c = S[i] - 'a';
        if (c < widthsSize) {
            w = widths[c];
            if (res[1] + w < 100) {
                res[1] += w;
            } else {
                res[0] ++;
                res[1] = res[1] + w == 100 ? 0 : w;
            }
        }
    }

    if (res[1] > 0) {
        res[0]++;
    }

    return res;
}

