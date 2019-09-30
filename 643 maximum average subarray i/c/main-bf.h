
/// brutal force
/// max time exceed
double findMaxAverage(int* nums, int numsSize, int k){
    double ma;
    for (int i = 0; i <= numsSize - k; i++) {
        int sum = 0;
        for (int j = i; j < i + k; j++) {
            sum += nums[j];
        }
        double avg = ((double) sum) / k;
        ma = (i == 0 || avg > ma) ? avg : ma;
    }

    return ma;
}
