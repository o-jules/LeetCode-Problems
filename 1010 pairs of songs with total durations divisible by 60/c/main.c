
int numPairsDivisibleBy60(int* time, int timeSize){
    int sum = 0;
    int map[60] = { 0 };
    for (int i = 0; i < timeSize; i++) {
        map[time[i] % 60]++;
    }
    for (int i = 0; i <= 30; i++) {
        sum += (i == 0 || i == 30) ?
            (map[i] * (map[i] - 1) / 2) :
            (map[i] * map[60 - i]);
    }
    return sum;
}
