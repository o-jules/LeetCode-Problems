
// edge case
// "a" 1
// "---" 3
char * licenseKeyFormatting(char * S, int K){
  if (K <= 0) {
    return S;
  }

  int count = 0, len = 0;
  while (S[len] != '\0') {
    if (S[len++] != '-') {
      count++;
    }
  }

  int group = count / K + (count % K > 0 ? 1 : 0);
  int size = count + group - 1;

  size = size <= 0 ? 0 : size;
  char *formated = malloc(sizeof(char) * (size + 1));
  formated[size--] = '\0';

  int acc = 0;
  while (len-- >= 0 && size >= 0) {
    if (S[len] != '-') {
      formated[size--] = S[len] >= 'a' && S[len] <= 'z' ? S[len] - 'a' + 'A' : S[len];
      if (++acc == K) {
        if (size >= 0) {
          formated[size--] = '-';
        }
        acc = 0;
      }
    }
  }

  return formated;
}
