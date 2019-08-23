

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
  int *rec = calloc(numsSize + 1, sizeof(int));

  *returnSize = numsSize;
  for (int i = 0; i < numsSize; i++) {
    if (rec[nums[i]] == 0) {
      (*returnSize)--;
    }
    rec[nums[i]]++;
  }

  int *missing = malloc(sizeof(int) * (*returnSize));
  int j = 0;
  for (int i = 1; i <= numsSize; i++) {
    if (rec[i] == 0) {
      missing[j++] = i;
    }
  }

  free(rec);
  return missing;
}
