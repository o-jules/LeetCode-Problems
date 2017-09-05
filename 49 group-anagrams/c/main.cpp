#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool compare(string &l, string &r) {
  int count = r.size();
  if (l.size() != count)
    return false;

  if (l.size() == 0 && count == 0)
    return true;

  vector<bool> used(count, false);
  for (char &c : l) {
    bool j = false;

    for(int i = 0; i < count; i++) {
      if (used[i]) {
        continue;
      } else {
        if (r[i] == c) {
          j = true;
          used[i] = true;
          break;
        }
      }
    }

    if (!j)
      return false;
  }

  return true;
}

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
  vector<vector<string>> groups;

  for (string &s : strs)
  {
    bool in_group = false;
    for (vector<string> &g : groups)
    {
      if (g[0].size() != s.size())
      {
        continue;
      }

      if (compare(s, g[0]))
      {
        in_group = true;
        g.push_back(s);
        break;
      }
    }

    if (!in_group)
    {
      vector<string> g;
      g.push_back(s);
      groups.push_back(g);
    }
  }

  return groups;
}


// ["ray","cod","abe","ned","arc","jar","owl","pop","paw","sky","yup","fed","jul","woo",
// "ado","why","ben","mys","den","dem","fat","you","eon","sui","oct","asp","ago","lea","sow",
// "hus","fee","yup","eve","red","flo","ids","tic","pup","hag","ito","zoo"]

// output
// [["ray"],["ned","den"],["owl","woo"],
// ["yup","yup","pup"],["fed","fee"],["ado"]]

// [["pup"],
// ["fee"],["den","ned"],["owl"],
// ["ray"],["yup","yup"],["woo"],["fed"]]

int main(void)
{
  vector<string> s = {"ray","ned","den","owl","woo", "yup","yup", "", "pup","fed","fee", "ado", ""};
  auto groups = groupAnagrams(s);
  for (auto &g : groups)
  {
    for (auto &w : g)
    {
      if (w.size() == 0)
        cout << "\\0";
      else
        cout << w << ",";
    }
    cout << endl;
  }
}
