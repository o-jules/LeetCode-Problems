/*
 * 设链表长度为n，则：
 *
 * 时间复杂度：O(n)
 *
 */

bool hasCycle(struct ListNode *head)
{
  if (head == NULL || head->next == NULL)
    return false;

  struct ListNode *fast = head->next;
  struct ListNode *slow = head;

  while (fast != slow)
  {
    if (fast == NULL || fast->next == NULL)
    {
      return false;
    }
    fast = fast->next->next;
    slow = slow->next;
  }

  return true;
}
