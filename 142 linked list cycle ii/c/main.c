/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if (!head || !head->next) {
        return NULL;
    }
    struct ListNode *p1, *p2, *p3;
    p1 = p2 = head;
    p3 = NULL;
    while (p2->next) {
        p1 = p1->next;
        p2 = p2->next;
        if (p2->next) {
            p2 = p2->next;
            if (p1 == p2) {
                p3 = p1;
                break;
            }
        }
    }
    if (!p3) {
        return NULL;
    }

    // detect length of circle and move p3 from head to the `n`th point
    p3 = head;
    do {
        p1 = p1->next;
        p3 = p3->next;
    } while (p1 != p2);

    p1 = head;
    while (p1 != p3) {
        p1 = p1->next;
        p3 = p3->next;
    }
    return p1;
}
