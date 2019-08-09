#include <math.h>

bool judgeSquareSum(int c){
    int m = (int)sqrt(c);
    for (int a = 0; a <= m; a++) {
        double b = sqrt(c - a*a);
        if (b == (int)b) {
            return true;
        }
    }

    return false;
}

