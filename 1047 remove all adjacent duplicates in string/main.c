

char * removeDuplicates(char * S){
    if (!S || !S[0]) {
        return S;
    }

    int i = 0, j = 1;
    while (S[j]) {
        if (i < 0 || S[i] != S[j]) {
            S[++i] = S[j];
        } else {
            i--;
        }
        j++;
    }
    S[i+1] = '\0';

    return S;
}
