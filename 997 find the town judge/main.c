
int findJudge(int N, int** trust, int trustSize, int* trustColSize){
    if (trustSize == 0) {
        return N == 1 ? 1 : -1;
    }

    *trustColSize = 2;
    int *truster = calloc(N + 1, sizeof(int));
    int *trusted = calloc(N + 1, sizeof(int));

    for (int i = 0; i < trustSize; i++) {
        truster[trust[i][0]]++;
        trusted[trust[i][1]]++;
    }

    int judge = 0;
    for (int i = 1; i <= N; i++) {
        if (truster[i] == 0) {
            if (judge == 0) {
                judge = i;
            } else {
                return -1;
            }
        }
    }

    if (judge == 0 || trusted[judge] != N - 1) {
        return -1;
    }

    free(truster);
    free(trusted);

    return judge;
}
