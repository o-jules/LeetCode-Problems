/**
 *
 * Leetcode 最优解
 */

var oddEvenList = function(head) {
  if(head === null)
		return head;

  let h1 = null, // odd head
    p1 = null, // odd node
    p = head,
    t = null;

	while(p.next && p.next.next) {
    t = p.next.next;
		if(h1 === null) {
			h1 = p.next;
			p1 = h1;
		} else {
			p1.next = p.next;
			p1 = p1.next;
    }

		p.next = p.next.next;
		p = p.next;
  }

	if(p.next) {
		if(h1 === null) {
			h1 = p.next;
			p1 = h1;
		} else {
			p1.next = p.next;
			p1 = p1.next;
		}
  }

  if(p1) {
    p1.next = null;
  }
  p.next = h1;0

	return head;
};
