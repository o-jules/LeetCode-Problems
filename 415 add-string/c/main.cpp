
string addStrings(string num1, string num2) {
  string s;

  int l1 = num1.size() - 1,
      l2 = num2.size() - 1;

  char i, j = 0;
  while (l1 >= 0 || l2 >= 0) {
    i = j;
    if (l1 >= 0)
      i += num1[l1] - '0';
    if (l2 >= 0)
      i += num2[l2] - '0';

    j = i/10;
    i = i%10 + '0';

    s.insert(0, 1, i);
    l1 --;
    l2 --;
  }

  if (j != 0) {
    s.insert(0, 1, j + '0');
  }

  return s;
}
