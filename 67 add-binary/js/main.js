function addBinary(a, b) {
  let s = [];
  let c = 0, r = 0;
  let ia = a.length - 1, ib = b.length - 1;

  while(ia >= 0 || ib >= 0) {
    c = 0;
    if (ia >= 0 && a[ia] == '1') {
      c++;
    }
    if (ib >= 0 && b[ib] == '1') {
      c++;
    }

    r += c;
    s.unshift(r % 2 === 0 ? '0': '1');
    r = r < 2 ? 0 : 1;

    ia --;
    ib --;
  }

  if (r !== 0) {
    s.unshift('1');
  }

  return s.join('');
}


console.log(addBinary('101', '111'))
