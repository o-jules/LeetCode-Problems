

void sortColors(int* nums, int numsSize){
    int white = 0, blue = 0;
    int j = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            nums[j++] = 0;
        } else if (nums[i] == 1) {
            white++;
        } else {
            blue++;
        }
    }

    while (white-- > 0) {
        nums[j++] = 1;
    }
    while (blue-- > 0) {
        nums[j++] = 2;
    }
}
