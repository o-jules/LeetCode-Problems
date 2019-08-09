

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    *returnSize = num_people;
    int *list = (int*)calloc(num_people, sizeof(int));

    int n = 1, i = 0;
    while (candies > 0) {
        list[i] += candies > n ? n : candies;
        candies -= n;
        n++;
        i++;
        if (i == num_people) {
            i = 0;
        }
    }
    return list;
}
