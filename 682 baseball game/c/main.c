#include <stdlib.h>

int calPoints(char ** ops, int opsSize){
    int validSize = -1;
    int *record = malloc(opsSize * sizeof(int));

    for (int i = 0; i < opsSize; i++) {
        char *rec = ops[i];
        if (rec[0] == 'C') {
            validSize--;
        } else if (rec[0] == 'D') {
            validSize++;
            record[validSize] = record[validSize - 1] * 2;
        } else if (rec[0] == '+') {
            validSize++;
            record[validSize] = record[validSize - 1] + record[validSize - 2];
        } else {
            validSize++;
            record[validSize] = atoi(ops[i]);
        }
    }

    int sum = 0;
    for (int i = 0; i <= validSize; i++) {
        sum += record[i];
    }
    free(record);

    return sum;
}


