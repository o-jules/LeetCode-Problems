
int countCharacters(char ** words, int wordsSize, char * chars){
    int map[26] = { 0 };
    int size = 0;
    while (chars[size]) {
        map[chars[size++] - 'a']++;
    }

    int sum = 0, j = 0, len = 0;
    int rec[26] = { 0 };
    for (int i = 0; i < wordsSize; i++) {
        char *c = words[i];
        while (c[len] != '\0') {
            j = c[len++] - 'a';
            rec[j]++;
            if (len > size || map[j] < rec[j]) {
                goto out;
            }
        }
        sum += len;

        out:
        for (int k = 0; k < 26; k++) {
            rec[k] = 0;
        }
        len = 0;
    }
    return sum;
}
