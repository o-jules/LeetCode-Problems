#include <stdlib.h>

#define IS_VOWEL(c) \
  (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || \
   c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')

void fill_goat(char *origin, char *goat, int start, int end, int index, int *j) {
    if (IS_VOWEL(origin[start])) {
        for (int k = start; k < end; k++) {
            goat[(*j)++] = origin[k];
        }
    } else {
        for (int k = start + 1; k < end; k++) {
            goat[(*j)++] = origin[k];
        }
        goat[(*j)++] = origin[start];
    }
    goat[(*j)++] = 'm';
    goat[(*j)++] = 'a';
    for (int k = 0; k < index; k++) {
      goat[(*j)++] = 'a';
    }
}

char * toGoatLatin(char * S){
    int word_count = 0;
    int len = 0;

    while (S[len] != '\0') {
      if (S[len] == ' ' || S[len + 1] == '\0') {
        word_count++;
      }
      len++;
    }
    int newLen = len + word_count * 2 + (1 + word_count) * word_count / 2;

    char *goat = malloc(sizeof(char) * (newLen + 1));
    int i = 0, j = 0;
    int start = 0;
    int index = 1;
    while (S[i] != '\0') {
        if (S[i] == ' ') {
            fill_goat(S, goat, start, i, index, &j);
            goat[j++] = ' ';
            index++;
            start = ++i;
        }
        i++;
    }

    fill_goat(S, goat, start, len, index, &j);

    goat[newLen] = '\0';
    return goat;
}
