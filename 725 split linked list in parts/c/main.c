
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize){
    *returnSize = k;

    int len = 0, spare, groupSize;
    struct ListNode* p = root;
    while (p) {
        len++;
        p = p->next;
    }
    spare = len % k;
    groupSize = (len - spare) / k;
    p = root;

    struct ListNode **list = malloc(sizeof(struct ListNode*) * k);
    for (int i = 0; i < k; i++) {
        int size = (spare-- > 0 ? 1 : 0) + groupSize;
        struct ListNode *item = NULL, *m;
        while (size-- > 0) {
            m = item ? (m->next = p, p) : (item = p, p);
            p = p->next;
        }
        if (m) m->next = NULL;
        list[i] = item;
    }

    return list;
}
