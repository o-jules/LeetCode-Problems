#include <iostream>

#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Score {
  int i;
  int val;
};
bool descend(Score l, Score r) {
  return l.val > r.val;
}

vector<string> findRelativeRanks(vector<int> &nums) {
  int len = nums.size();

  vector<Score> cache;
  for (int i = 0; i < len; i++) {
    Score s = {i, nums[i]};
    cache.push_back(s);
  }
  sort(cache.begin(), cache.end(), descend);

  vector<string> rank(len, "");
  for (int i = 0; i < len; i++) {
    string s;

    switch (i) {
    case 0:
      s = "Gold Medal";
      break;
    case 1:
      s = "Silver Medal";
      break;
    case 2:
      s = "Bronze Medal";
      break;
    default:
      s = to_string(i + 1);
      break;
    }

    rank[cache[i].i] = s;
  }
  return rank;
}

int main(void)
{
}
