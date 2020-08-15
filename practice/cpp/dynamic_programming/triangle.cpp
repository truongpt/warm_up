// problem: https://leetcode.com/problems/triangle

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int minPath(vector<vector<int>>& triangle) {
    vector<int> dp (triangle.back());
    int n = triangle.size();
    for (int l = n-2; l >= 0; l--) {
      for (int i = 0; i < triangle[l].size(); i++) {
        dp[i] = min(dp[i], dp[i+1]) + triangle[l][i];
      }
    }
    return dp[0];
  }
};

int main(void)
{
  Solution sol;
  vector<vector<int>> v;
  v.push_back({-1});
  v.push_back({3,2});
  v.push_back({-3,1-1});
  cout << sol.minPath(v) << endl;
}
