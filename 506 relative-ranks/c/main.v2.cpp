/**
 * Leetcode上的最优解
 * 使用到了C++的lambda
 */
vector<string> findRelativeRanks(vector<int>& nums) {
  int n = nums.size();
  vector<string> ret(n, "");

  vector<int> index(n, 0);
  for(int i=0; i<n; i++)
    index[i] = i;

  auto comp = [&nums](const int& a, const int& b) {
    return nums[a] > nums[b];
  };
  sort(index.begin(), index.end(), comp);

  for(int i=0; i<n; i++) {
      if(i==0) ret[index[i]]="Gold Medal";
      else if(i==1) ret[index[i]]="Silver Medal";
      else if(i==2) ret[index[i]]="Bronze Medal";
      else ret[index[i]]=to_string(i+1);
  }

  return ret;
}
