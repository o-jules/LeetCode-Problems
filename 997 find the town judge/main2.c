
int findJudge(int N, int** trust, int trustSize, int* trustColSize){
    if (trustSize == 0) {
        return N == 1 ? 1 : -1;
    }

    *trustColSize = 2;
    int *rec = calloc(N + 1, sizeof(int));

    for (int i = 0; i < trustSize; i++) {
        rec[trust[i][0]]--;
        rec[trust[i][1]]++;
    }

    int judge = 0;
    for (int i = 1; i <= N; i++) {
        if (rec[i] == N - 1) {
            if (judge == 0) {
                judge = i;
            } else {
                return -1;
            }
        }
    }
    free(rec);

    return judge == 0 ? -1 : judge;
}
