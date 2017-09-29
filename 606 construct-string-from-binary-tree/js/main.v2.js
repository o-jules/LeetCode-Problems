
var tree2str = function(t) {
  if (t === null)
    return ''

  return t.val + (
    (t.left || t.right) ?
    '(' + tree2str(t.left) + ')' :
    ''
  ) + (
    t.right ?
    '(' + tree2str(t.right) + ')' :
    ''
  )
};
