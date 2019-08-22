
bool isSubsequence(char * s, char * t){
    char *p1 = s, *p2 = t;
    while (*p1) {
        while (*p2) {
            if (*p1 == *p2++) {
                p1++;
                break;
            }
        }

        if (!(*p2)) {
            break;
        }
    }


    return !(*p1);
}
