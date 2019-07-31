#include <string.h>
#include <stdlib.h>

char *defangIPaddr(char *address){
    int len = strlen(address) + 6;
    char *defang = malloc(sizeof(char) * (len + 1));
    memset(defang, '0', len);
    defang[len] = '\0';

    char *p1 = defang, *p2 = address;
    while (*p2 != '\0') {
        if (*p2 == '.') {
            *p1++ = '[';
            *p1++ = '.';
            *p1++ = ']';
        } else {
            *p1++ = *p2;
        }
        p2++;
    }
    return defang;
}
