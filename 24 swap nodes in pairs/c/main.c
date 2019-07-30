/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    if (!head || !head->next) {
        return head;
    }
    // p: previous
    // c: current
    // t: temporal
    // h: head
    struct ListNode *p, *c, *t, *h;
    h = head->next;

    c = head;
    p = NULL;
    while (c && c->next) {
        t = c->next;
        c->next = t->next;
        t->next = c;
        if (p) {
            p->next = t;
        }
        p = c;
        c = c->next;
    }
    return h;
}

