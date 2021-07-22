/*
- Problem: https://leetcode.com/problems/partition-array-into-disjoint-intervals
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int partitionDisjoint(std::vector<int>& nums) {
  int n = nums.size();
  std::vector<int> min_nums(n, INT_MAX), max_nums(n, INT_MIN);
  int min_value = INT_MAX, max_value = INT_MIN;

  for (int i = 0; i < n; i++) {
    min_value = std::min(nums[n-i-1], min_value);
    max_value = std::max(nums[i], max_value);
    min_nums[n-i-1] = min_value;
    max_nums[i] = max_value;
  }

  for (int i = 1; i < n; i++) {
    if (min_nums[i] >= max_nums[i-1]) {
      return i;
    }
  }

  return -1;
}


int main(void) {
  std::vector<int> nums = {5,0,3,6,8};
  auto index = partitionDisjoint(nums);
  std::cout << "index: " << index << std::endl;
}
