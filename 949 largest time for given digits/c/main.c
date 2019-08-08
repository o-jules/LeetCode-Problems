
char * largestTimeFromDigits(int* A, int ASize) {
    int ln = -1;
    int l1, l2, l3, l4;

    for (int i = 0; i < 4; i++) {
      if (A[i] > 2) continue;

      for (int j = 0; j < 4; j++) {
        if (j == i || (A[i] == 2 && A[j] > 3)) continue;

        for (int k = 0; k < 4; k++) {
          if (k == i || k == j || A[k] > 5) continue;

          for (int l = 0; l < 4; l++) {
            if (l == i || l == j || l == k) continue;

            int count = (A[i] * 10 + A[j]) * 3600 + (A[k] * 60 + A[l]);
            if (count > ln) {
              l1 = A[i];
              l2 = A[j];
              l3 = A[k];
              l4 = A[l];
              ln = count;
            }
          }
        }
      }
    }

    if (ln < 0) {
      char *empty = (char*) malloc(sizeof(char));
      empty[0] = '\0';
      return empty;
    } else {
      char *time = (char *)malloc(sizeof(char) * 6);
      time[0] = (char) (l1 + '0');
      time[1] = (char) (l2 + '0');
      time[2] = ':';
      time[3] = (char) (l3 + '0');
      time[4] = (char) (l4 + '0');
      time[5] = '\0';
      return time;
    }
}
