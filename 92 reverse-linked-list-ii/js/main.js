/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} m
 * @param {number} n
 * @return {ListNode}
 */
var reverseBetween = function(head, m, n) {
  if (head === null || m === n)
    return head

  let p = head
  // m = 2, n = 4
  // 1->  2->3->4-> 5->NULL
  // nt = .2, nh = .4
  // oh = .1, ot = .5

  let oh = null, ot = null
  let nh = null, nt = null

  let t  = null, t2 = null, i = 1
  while (i <= n) {
    if (i == m - 1) {
      oh = p
    } else if (i == m) {
      nt = p
    } else if (i == n) {
      ot = p.next
      nh = p
    }

    t2 = p.next
    if (i >= m && i <= n) {
      p.next = t
      t = p
    }

    i++
    p = t2
  }

  if (oh) {
    oh.next = nh
  } else {
    head = nh
  }

  if (nt) {
    nt.next = ot
  }

  return head
};

function gen(n) {
  let p, h, t

  for (let i = 1; i <= n; i++) {
    t = { val: i, next: null }

    if (p) {
      p.next = t
      p = p.next
    } else {
      p = t
    }
    if (!h) h = p
  }

  return h
}



// 测试：
function test(c, m, n) {
  let l = gen(c)
  let nl = reverseBetween(l, m, n)

  view(nl)
}

function view(l) {
  let s = ''
  while (l) {
    s += '->' + l.val
    l = l.next
  }
  console.log(s)
}

test(5, 2, 4)
test(5, 4, 5)
test(5, 1, 5)
test(5, 1, 3)
test(2, 1, 2)
test(3, 1, 2)
