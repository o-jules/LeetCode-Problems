

int maxNumberOfBalloons(char * text){
    int len = strlen(text);
    if (len < 7) {
        return 0;
    }

    int counts[26] = {0};
    // b 1, a 1, l 2, o 2, n 1
    char alphabet[5] = {'b', 'a', 'l', 'o', 'n'};

    for (int i = 0; i < len; i++) {
        counts[text[i] - 'a'] ++;
    }
    counts['l' - 'a'] /= 2;
    counts['o' - 'a'] /= 2;

    int max = 0;
    for (int i = 0; i < 5; i++) {
        int c = counts[alphabet[i] - 'a'];
        if (i == 0 || c < max) {
            max = c;
        }
    }
    return max;
}

