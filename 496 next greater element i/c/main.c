

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    *returnSize = nums1Size;
    int *result = (int *)malloc(sizeof(int) * nums1Size);

    for (int i = 0; i < nums1Size; i++) {
        int k = -1, catch = 0;
        for (int j = 0; j < nums2Size; j++) {
            if (catch) {
                if (nums2[j] > nums1[i]) {
                    k = nums2[j];
                    break;
                }
            } else {
                if (nums1[i] == nums2[j]) {
                    catch = 1;
                }
            }
        }
        result[i] = k;
    }

    return result;
}
