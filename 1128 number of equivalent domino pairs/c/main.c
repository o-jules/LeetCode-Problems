
/**
 * Time O(N^2)
 * Space O(N)
 */
int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize){
    *dominoesColSize = 2;

    int *record = (int *)calloc(dominoesSize, sizeof(int));
    int pairs = 0, count = 0, match = 0;
    int *cur, *next;
    for (int i = 0; i < dominoesSize; i++) {
        if (record[i]) {
            continue;
        }
        record[i] = 1;
        cur = dominoes[i];
        count = 1;
        for (int j = i + 1; j < dominoesSize; j++) {
            next = dominoes[j];
            match = (cur[0] == next[0] && cur[1] == next[1]) || (cur[1] == next[0] && cur[0] == next[1]);
            if (match) {
                record[j] = 1;
                count++;
            }
        }
        if (count > 1) {
            pairs += count * (count - 1) / 2;
        }
    }

    return pairs;
}

