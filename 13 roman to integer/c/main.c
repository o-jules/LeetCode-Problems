
int romanToInt(char * s){
    char *p = s, *np;
    int n = 0;
    while (*p) {
        if (*p == 'I') {
            np = p + 1;
            if (*np) {
                if (*np == 'V') {
                    n += 4;
                    p++;
                } else if (*np == 'X') {
                    n += 9;
                    p++;
                } else {
                    n += 1;
                }
            } else {
                n += 1;
            }
        } else if (*p == 'X') {
            np = p + 1;
            if (*np) {
                if (*np == 'L') {
                    n += 40;
                    p++;
                } else if (*np == 'C') {
                    n += 90;
                    p++;
                } else {
                    n += 10;
                }
            } else {
                n += 10;
            }
        } else if (*p == 'C') {
            np = p + 1;
            if (*np) {
                if (*np == 'D') {
                    n += 400;
                    p++;
                } else if (*np == 'M') {
                    n += 900;
                    p++;
                } else {
                    n += 100;
                }
            } else {
                n += 100;
            }
        } else if (*p == 'V') {
            n += 5;
        } else if (*p == 'L') {
            n += 50;
        } else if (*p == 'D') {
            n += 500;
        } else if (*p == 'M') {
            n += 1000;
        }

        p++;
    }

    return n;
}
