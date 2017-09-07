#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int distributeCandies(vector<int>& candies) {
  int half = candies.size() / 2;
  int max = 0;

  unordered_set<int> cache;
  for(int &c: candies) {
    if (max >= half) {
      return half;
    }

    auto s = cache.find(c);
    if (s == cache.end()) {
      cache.insert(c);
      max ++;
    }
  }

  return max;
}

int main(void) {
  vector<int> candies = {1,1,1,1,2,2,2,3,3,3};
  int i = distributeCandies(candies);
  cout << i << endl;
}
