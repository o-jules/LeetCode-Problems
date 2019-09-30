#include <stdlib.h>

#define MAX_LEN 10

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numSmallerByFrequency(char ** queries, int queriesSize, char ** words, int wordsSize, int* returnSize){
    *returnSize = queriesSize;

    int *res = (int *) malloc(queriesSize * sizeof(int));
    int count = 0;
    int count_map[12] = {0};
    char lead = 127, *s;

    while (wordsSize --> 0) {
        s = words[wordsSize];
        lead = 127;
        count = 0;
        for (int i = 0; s[i] && i <= MAX_LEN; i++) {
            if (s[i] < lead) {
              lead = s[i];
              count = 1;
            } else if (s[i] == lead) {
              count++;
            }
        }
        count_map[count]++;
    }

    for (int i = MAX_LEN; i >= 1; i--) {
      count_map[i] += count_map[i + 1];
    }

    while (queriesSize --> 0) {
        lead = 127;
        count = 0;
        s = queries[queriesSize];
        for (int i = 0; s[i] && i <= MAX_LEN; i++) {
            if (s[i] < lead) {
              lead = s[i];
              count = 1;
            } else if (s[i] == lead) {
              count++;
            }
        }

        res[queriesSize] = count_map[count + 1];
    }

    return res;
}
