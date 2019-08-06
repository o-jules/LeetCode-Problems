

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** commonChars(char ** A, int ASize, int* returnSize){
    // record of a - z
    int size = 123; // 'z' = 122
    int record[123];
    for (int i = 0; i < 123; i++) {
      record[i] = -1;
    }
    int patch[123] = { 0 };
    for (int i = 0; i < ASize; i++) {
        char *s = A[i];
        while (*s) {
            patch[*s]++;
            s++;
        }

        for (int j = 'a'; j < size; j++) {
            record[j] =
                record[j] == -1 ?
                patch[j] :
                record[j] > patch[j] ? patch[j] : record[j];
        }

        for (int k = 0; k < 123; k++) {
          patch[k] = 0;
        }
    }

    int count = 0;
    for (int j = 'a'; j < size; j++) {
        if (record[j] > 0) {
            count += record[j];
        }
    }

    *returnSize = count;
    char **returnA = (char **)malloc(sizeof(char*) * count);
    int i = 0;
    for (int j = 'a'; j < size; j++) {
        int k = record[j];
        while (k > 0) {
            char *ss = (char *)malloc(sizeof(char)*2);
            ss[1]='\0';
            ss[0]= (char) j;
            returnA[i] = ss;
            i++;
            k--;
        }
    }

    return returnA;
}
