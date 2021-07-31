/*
- Problem: https://leetcode.com/problems/trapping-rain-water/
*/

#include <iostream>
#include <vector>
#include <algorithm>

int trapRainWater(std::vector<int> height) {
  int n = height.size();
  std::vector<std::pair<int,int>> edge{};
  int cur = 0;
  int res = 0;
  int pre = 0;

  for (int i = 0; i < n; i++) {
    while (!edge.empty()) {
      if (height[i] > edge.back().second) {
        auto cur = edge.back();
        int add = cur.second - pre;
        res += add*(i - cur.first - 1);
        pre = edge.back().second;
        edge.pop_back();
      } else {
        auto cur = edge.back();
        int add = height[i] - pre;
        res += add*(i - cur.first - 1);
        break;
      }
    }

    if (edge.empty() || height[i] <= edge.back().second) {
      edge.push_back({i,height[i]});
      pre = height[i];
    }
  }
  return res;
}

int main(void) {
  {
    std::vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    std::cout << trapRainWater(height) << std::endl;
  }

  {
    std::vector<int> height = {4,2,0,3,2,5};
    std::cout << trapRainWater(height) << std::endl;
  }
}
