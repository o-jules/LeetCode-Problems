

int search(int* nums, int numsSize, int target){
    int l = 0, r = numsSize - 1, m = 0;

    while (l <= r) {
        m = l + (r - l) / 2;
        if (target == nums[m]) {
            return m;
        } else if (target < nums[m]) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return -1;
}
