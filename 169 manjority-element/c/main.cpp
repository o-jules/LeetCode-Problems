#include <vector>
#include <unordered_map>

using namespace std;

int majorityElement(vector<int>& nums) {
  int size = nums.size();
  if (size == 0)
    return 0;
  if (size <= 2)
    return nums[0];

  unordered_map<int, int> cache;
  for (int &i : nums) {
    auto s = cache.find(i);
    if (s != cache.end()) {
      s->second ++;
      if (s->second > size/2) {
        return i;
      }
    } else {
      cache.insert({i, 1});
    }
  }

  return 0;
}
