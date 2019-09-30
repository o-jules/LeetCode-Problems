
// sliding window
double findMaxAverage(int* nums, int numsSize, int k){
    int max_sum, sum = 0;
    for (int i = 0; i < k; i++) sum += nums[i];
    max_sum = sum;

    for (int i = 1; i <= numsSize - k - 1; i++) {
      sum = sum - nums[i - 1] + nums[i + k - 1];
      max_sum = sum > max_sum ? sum : max_sum;
    }

    return ((double) max_sum) / k;
}
