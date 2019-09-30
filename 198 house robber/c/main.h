#include <string.h>

int robMax(int *nums, int all, int from, int *rec) {
    if (from >= all) {
        return 0;
    }

    int m1 = 0, m2 = 0;
    int f1 = from + 1, f2 = from + 2;
    if (f1 < all) {
        if (rec[f1] != -1) {
            m1 = rec[f1];
        } else {
            m1 = nums[f1] + robMax(nums, all, f1 + 1, rec);
            rec[f1] = m1;
        }
    }

    if (f2 < all) {
        if (rec[f2] != -1) {
            m2 = rec[f2];
        } else {
            m2 = nums[f2] + robMax(nums, all, f2 + 1, rec);
            rec[f2] = m2;
        }
    }

    return m1 > m2 ? m1 : m2;
}

int rob(int* nums, int numsSize){
    int *rec = malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        rec[i] = -1;
    }

    return robMax(nums, numsSize, -1, rec);
}

