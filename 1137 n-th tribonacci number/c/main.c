int cache[38] = {0};

int tribonacci(int n){
    if (n == 0 || n == 1) {
        return n;
    }
    if (n == 2) {
        return 1;
    }
    cache[0] = 0;
    cache[1] = 1;
    cache[2] = 1;

    int t0 = cache[n - 3];
    int t1 = cache[n - 2];
    int t2 = cache[n - 1];
    if (n > 3 && t0 == 0) {
        t0 = tribonacci(n - 3);
        cache[n - 3] = t0;
    }
    if (t1 == 0) {
        t1 = tribonacci(n - 2);
        cache[n - 2] = t1;
    }
    if (t2 == 0) {
        t2 = tribonacci(n - 1);
        cache[n - 1] = t2;
    }
    return t0 + t1 + t2;
}
