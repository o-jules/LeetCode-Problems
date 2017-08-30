
class LNode {
  val: number
  next: LNode

  constructor(v: number, n: LNode = null) {
    this.value = v
    this.next = n
  }

  set value(v: number) {
    if (v < 0) v = 0;
    if (v > 9) v = 9;
    this.val = v;
  }

};

function valueOf(node: LNode): number {
  return node === null ? 0 : node.val
}

function addTwo(l1: LNode, l2: LNode): LNode {
  let list = new LNode(0), head = list
  let p = l1, q = l2
  let carry = 0

  while (l1 != null || l2 != null) {
    let sum = valueOf(p) + valueOf(q) + carry
    carry = Math.floor(sum / 10)
    sum -= carry * 10

    head.next = new LNode(sum)
    head = head.next

    if (p !== null) p = p.next
    if (q !== null) q = q.next
  }

  if (carry > 0) {
    head.next = new LNode(carry)
  }

  return list.next
}

// test:
function genNumber(n: number): LNode {
  if (n < 0) n = 0
  let node = null, prev = null;
  while (n > 0) {
    if (node === null) {
      prev = node = new LNode(n % 10)
    }
    else {
      prev.next = new LNode(n % 10)
      prev = prev.next
    }
    n = Math.floor(n /= 10)
  }
  return node
}

const a = genNumber(13456)
const b = genNumber(2194014)
