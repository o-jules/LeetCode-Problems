
/**
 * Time O(N)
 * Space O(1)
 */
int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize){
    *dominoesColSize = 2;
    int hash[10][10];
    memset(hash, 0, sizeof(int) * 100);

    int pairs = 0;
    int *cur;
    for (int i = 0; i < dominoesSize; i++) {
      cur = dominoes[i];
      if (cur[0] > cur[1]) {
        hash[cur[1]][cur[0]]++;
      } else {
        hash[cur[0]][cur[1]]++;
      }
    }

    for (int i = 0; i < 10; i++) {
      for (int j = i; j < 10; j++) {
        if (hash[i][j] > 0) {
          pairs += hash[i][j] * (hash[i][j] - 1) / 2;
        }
      }
    }
    return pairs;
}
