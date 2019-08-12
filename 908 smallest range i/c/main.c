
int smallestRangeI(int* A, int ASize, int K){
    int min = 10000, max = 0;
    for (int i = 0; i < ASize; i ++) {
        if (A[i] < min) min = A[i];
        if (A[i] > max) max = A[i];
    }
    int pad = (max - K) - (min + K);
    return pad < 0 ? 0 : pad;
}
