
string longestCommonPrefix(vector<string> &strs) {
  if (strs.empty())
    return "";

  string d;

  int i = 0;
  char *cur;
  string first = strs[0];
  int flen = first.size();
  int count = strs.size();

  for (int i = 0; i < flen; i++)
  {
    cur = &(first[i]);
    for (int j = 1; j < count; j++)
    {
      if (strs[j][i] != *cur)
      {
        goto OUT;
      }
    }
    d.push_back(*cur);
  }

OUT:
  return d;
}
