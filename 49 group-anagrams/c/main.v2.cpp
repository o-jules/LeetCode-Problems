
vector<vector<string>> groupAnagrams(vector<string>& strs) {
  vector<vector<string>> result;
  if (!strs.empty())
  {
      unordered_map<string, size_t> hashMap;
      for (string str : strs)
      {
          string s(str);
          sort(s.begin(), s.end());
          unordered_map<string, size_t>::iterator got = hashMap.find(s);
          if (got == hashMap.end())
          {
              vector<string> temp;
              temp.push_back(str);
              result.push_back(temp);
              hashMap.insert({s, result.size()-1});
          }
          else
          {
              result[got->second].push_back(str);
          }
      }
  }
  return result;
}
