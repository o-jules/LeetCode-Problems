
char * alphabetBoardPath(char * target){
    int size = strlen(target);
    char **rec = malloc(sizeof(char*) * size);

    // previous position
    int px = 0, py = 0, len = 0;
    for (int i = 0; i < size; i++) {
        int r = target[i] - 'a' + 1;
        // current position
        int cx = (r%5 == 0 ? 4: r%5 - 1);
        int cy = (r - 1)/5;

        // moves
        int x = cx - px;
        int y = cy - py;
        char sy = y > 0 ? 'D' : 'U';
        char sx = x > 0 ? 'R' : 'L';

        x = x < 0 ? -x : x;
        y = y < 0 ? -y : y;
        int c = x + y;
        len += c + 1;

        char *item = malloc(sizeof(char) * (c + 2));
        item[c] = '!';
        item[c + 1] = '\0';
        rec[i] = item;

        int dy = 0; // dangling y
        if (r == 26 && px > 0) {
          dy = 1 ;
          y--;
        }
        while (y-- > 0) {
            *item++ = sy;
        }
        while (x-- > 0) {
            *item++ = sx;
        }
        if (dy) {
          *item++ = sy;
        }

        px = cx;
        py = cy;
    }

    char *result = malloc(sizeof(char) * (len + 1));
    result[len] = '\0';
    int k = 0;
    for (int i = 0; i < size; i++) {
        char *item = rec[i];
        while (*item) {
            result[k++] = *item++;
        }
        free(rec[i]);
    }
    free(rec);

    return result;
}
