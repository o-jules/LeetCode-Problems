/**
 * 较优解：
 * 思路即 糖果种类数 与 糖果个体总数一半 的最小值
 */
int distributeCandies(vector<int>& candies) {
  unordered_set<int> candytype(candies.begin(),candies.end());
  return min(candytype.size(),candies.size() / 2);
}
