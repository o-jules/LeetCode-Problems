#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > imageSmoother(vector<vector<int> >& M) {
  int row = M.size(), col = M[0].size();

  int n, sum;
  int x, y;

  vector<vector<int> > N(row, vector<int>(col, 0));
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      n = 0;  sum = 0;

      for (x = i - 1; x <= i + 1; x++) {
        for(y = j - 1; y <= j + 1; y++) {
          if (x >= 0 && y >= 0 && x < row  && y < col) {
            n++;
            sum += M[x][y];
          }
        }
      }
      N[i][j] = sum/n;
    }
  }

  return N;
}

int main(void) {
  vector<vector<int> > img = {
    {1, 0, 1},
    {1, 6, 1},
    {1, 0, 1}
  };

  vector<vector<int> > newImg = imageSmoother(img);

  for (auto &r: newImg) {
    for (int &i: r) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}
