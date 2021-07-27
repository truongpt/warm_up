/*
- Problem: https://leetcode.com/problems/3sum-closest
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int threeSumClosest(std::vector<int>& nums, int target) {
  std::sort(nums.begin(), nums.end());

  int diff = INT_MAX;
  int result = 0;

  for (int i = 0; i < nums.size() - 2; i++) {
    for (int j = i+1; j < nums.size() - 1; j++) {
      int sum2 = nums[i] + nums[j];
      int remain = target - sum2;
      int left = j+1, right = nums.size()-1;
      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == remain) {
          return target;
        } else if (nums[mid] < remain) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }

      if (right > j && right < nums.size() && diff > abs(sum2 + nums[right] - target)) {
        result = sum2 + nums[right];
        diff = abs(sum2 + nums[right] - target);
      }

      if (left > j && left < nums.size() && diff > abs(sum2 + nums[left] - target)) {
        result = sum2 + nums[left];
        diff = abs(sum2 + nums[left] - target);
      }
    }
  }

  return result;
}

int main() {
  std::vector<int> nums = {-1,2,1,-4};
  std::cout << threeSumClosest(nums, 1) << std::endl;
}
