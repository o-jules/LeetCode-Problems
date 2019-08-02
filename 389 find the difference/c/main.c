
#include <string.h>

char findTheDifference(char * s, char * t){
    int c1[124] = {0};
    int c2[124] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        c1[s[i]]++;
        c2[t[i]]++;
    }
    c2[t[len]]++;

    for (int i = 'a'; i <= 'z'; i++) {
        if (c1[i] != c2[i]) {
            return (char) i;
        }
    }
    return '\0';
}


