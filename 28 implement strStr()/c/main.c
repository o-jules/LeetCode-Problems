#include <string.h>

int strStr(char * haystack, char * needle){
    if (needle[0] == '\0') return 0;
    if (haystack[0] == '\0') return -1;
    int nl = strlen(needle);
    int hl = strlen(haystack);
    if (hl < nl) return -1;

    int i, j;
    for (i = 0; i < hl - nl + 1; i++) {
        for (j = 0; j < nl; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (j == nl) {
            return i;
        }
    }

    return -1;
}

