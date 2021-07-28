/*
- Problem: https://leetcode.com/problems/beautiful-array
*/

#include <iostream>
#include <vector>

std::vector<int> beautifulArray(int n) {
  std::vector<int> arr = {1};
  while (arr.size() < n) {
    std::vector<int> temp{};
    for (auto it : arr) {
      if (it*2 - 1 <= n) {
        temp.push_back(it*2-1);
      }
    }

    for (auto it : arr) {
      if (it*2 <= n) {
        temp.push_back(it*2);
      }
    }
    arr = temp;
  }

  return arr;
}

int main(void) {
  auto result = beautifulArray(5);
  for (auto it : result) {
    std::cout << it << std::endl;
  }
  return 0;
}
