#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
  vector<vector<int>> trgl;

  for (int i = 0; i < numRows; i++) {
    vector<int> row(i + 1, 1);
    if (i > 1) {
      for (int j = 0; j <= i; j++) {
        if (j == 0 || j == i)
          continue;
        row[j] = trgl[i - 1][j - 1] + trgl[i - 1][j];
      }
    }
    trgl.push_back(row);
  }

  return trgl;
}

int main(void) {
  auto t = generate(6);

  cout << t.size() << endl;

  for (auto &r: t) {
    for (int &i: r) {
      cout << i << " ";
    }
    cout << endl;
  }
}
