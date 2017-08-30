/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

int advance(ListNode *&n)
{
	if (n == nullptr) return 0;

	int v = n->val;
	n = n->next;
	return v;
}

class Solution
{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		auto list = new ListNode(0), head = list;
		auto p = l1, q = l2;
		int carry = 0;

		while (p != nullptr || q != nullptr)
		{
			int sum = advance(p) + advance(q) + carry;
			carry = sum / 10;
			sum -= carry * 10;
			head->next = new ListNode(sum);
			head = head->next;
		}

		if (carry > 0)
		{
			head->next = new ListNode(carry);
		}

		return list->next;
	}
};
