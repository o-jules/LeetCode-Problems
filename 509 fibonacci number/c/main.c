

int fib(int N){
    if (N == 0 || N == 1) {
        return N;
    }
    int n1 = 0, n2 = 1;
    int t;
    while (N >= 2) {
        t = n2;
        n2 = n1 + n2;
        n1 = t;
        N--;
    }
    return n2;
}
