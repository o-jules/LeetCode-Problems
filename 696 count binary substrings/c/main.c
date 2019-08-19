
int countBinarySubstrings(char * s){
    if (s == NULL || s[0] == '\0') {
        return 0;
    }

    int sum = 0;
    char c = s[0];
    int i = 1, j = 0;
    while (s[i]) {
        if (s[i] == c) {
            i++;
        } else {
            break;
        }
    }
    int n1 = i, n2 = 0;
    while (s[i]) {
        c = s[i];
        j = i + 1;
        while (s[j]) {
            if (s[j] == c) {
                j++;
            } else {
                break;
            }
        }
        n2 = j - i;
        sum += n1 > n2 ? n2 : n1;

        n1 = n2;
        i = j;
    }

    return sum;
}
