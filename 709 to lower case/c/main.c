char* toLowerCase(char* str) {
    static int gap = 'a' - 'A';

    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (*(str+i) >= 'A' && *(str+i) <= 'Z') {
            *(str+i) = *(str+i) + gap;
        }
    }
    return str;
}
