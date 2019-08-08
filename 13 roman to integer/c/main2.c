
#define ROMAN_TO_INT (i) i == 'I' ? 1  : i == 'V' ?   5 : i == 'X' ? 10  : \
                         i == 'L' ? 50 : i == 'C' ? 100 : i == 'D' ? 500 : i == 'M' ? 1000 : 0

int romanToInt(char * s){
    if (s == NULL) {
      return 0;
    }

    char *p = s, *n;
    int prev = 0, cur = 0, num = 0;
    while (*p) {
        cur = ROMAN_TO_INT(*p);
        if (prev < cur) {
            num -= prev;
        } else {
            num += prev;
        }
        prev = cur;
    }

    // num += ROMAN_TO_INT(s[len-1]);
    return num;
}


