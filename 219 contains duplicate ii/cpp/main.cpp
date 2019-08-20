#include <unordered_map>

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> cache;
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            auto f = cache.find(nums[i]);
            if (f != cache.end() && i - f->second <= k) {
                return true;
            }
            cache[nums[i]] = i;
        }
        return false;
    }
};
