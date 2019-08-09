
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCasePermutation(char * S, int* returnSize){
  char *p = S;
  int count = 0; // letter count
  int len = 0;
  while (*p) {
    if ((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z')) {
      count++;
    }
    len++;
    p++;
  }

  *returnSize = 1;
  while (count-- > 0) {
    *returnSize *= 2;
  }

  char **res = (char **)malloc(sizeof(char*) * (*returnSize));
  for (int i = 0; i < *returnSize; i++) {
    char *s = (char *)malloc(sizeof(char) * (len + 1));
    s[len] = '\0';
    res[i] = s;
  }

  char lower = 'a' - 'A';
  char upper = 'A' - 'a';
  int gap = 1;
  for (int i = 0; i < len; i++) {
    char s = S[i];
    char sc = (S[i] >= 'A' && S[i] <= 'Z') ? (char)(S[i] + lower) :
              (S[i] >= 'a' && S[i] <= 'z') ? (char)(S[i] + upper) : '\0';
    int k = 0;
    for (int j = 0; j < *returnSize; j++) {
      if (sc) {
        if (k++ < gap) {
          res[j][i] = s;
        } else {
          res[j][i] = sc;
          if (k - gap == gap) {
            k = 0;
          }
        }
      } else {
        res[j][i] = S[i];
      }
    }

    if (sc) {
      gap *= 2;
    }
  }

  return res;
}
