/*
- Problem: https://leetcode.com/problems/three-equal-parts/
*/

#include <iostream>
#include <vector>
#include <numeric>

std::vector<int> threeEqualParts(std::vector<int>& arr) {
  int n = arr.size();
  int one_total = 0;
  one_total = std::accumulate(arr.begin(), arr.end(), 0);
  if (one_total == 0) {
    return {0,n-1};
  }

  if (one_total % 3 != 0) {
    return {-1,-1};
  }
  int one_part = one_total / 3;
  std::vector<int> pos(3,0);
  int one_count = 0;

  for (int i = 0; i < arr.size(); i++) {
    if (arr[i]) {
      if (one_count % one_part == 0) {
        pos[one_count / one_part] = i;
      }
      one_count++;
    }
  }

  while (pos[2] < n && arr[pos[0]] == arr[pos[1]] && arr[pos[1] == pos[2]]) {
    pos[0]++;
    pos[1]++;
    pos[2]++;
  }
  return {pos[0]-1, pos[1]};
}

int main(void)
{
  std::vector<int> arr = {1,0,1,0,1};
  auto result = threeEqualParts(arr);
  for (auto it : result) {
    std::cout << it << ",";
  }
  std::cout << std::endl;

}
