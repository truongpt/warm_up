// problem: https://leetcode.com/problems/range-sum-query-2d-immutable/
#include <iostream>
#include <vector>

using namespace std;

class NumMatrix{
public:
  vector<vector<int>> d;
  NumMatrix(vector<vector<int>>& m) {
    if (m.size() == 0) return;
    int r = m.size(), c = m[0].size();
    d = vector<vector<int>>(r, vector<int>(c,0));
    
    d[0][0] = m[0][0];
    for (int i = 1; i < r; i++) {
      d[i][0] = m[i][0]+d[i-1][0];
    }

    for (int i = 1; i < c; i++) {
      d[0][i] = m[0][i]+d[0][i-1];
    }
    for (int i = 1; i < r; i++) {
      for (int j = 1; j < c; j++) {
        d[i][j] = m[i][j] + d[i-1][j] + d[i][j-1] - d[i-1][j-1];
      }
    }

  }
  
  int sumRegion(int row1, int col1, int row2, int col2)
  {
    if (row1 == 0 && col1 == 0) return d[row2][col2];
    if (row1 == 0) return d[row2][col2] - d[row2][col1-1];
    if (col1 == 0) return d[row2][col2] - d[row1-1][col2];
    return d[row2][col2] - d[row1-1][col2] - d[row2][col1-1] + d[row1-1][col1-1];
  }
};

int main(){
  
  vector<vector<int>> m = {
  {3, 0, 1, 4, 2},
  {5, 6, 3, 2, 1},
  {1, 2, 0, 1, 5},
  {4, 1, 0, 1, 7},
  {1, 0, 3, 0, 5}
  };
  NumMatrix* ma = new NumMatrix(m);
  cout << ma->sumRegion(2,1,4,3) << endl;

}


