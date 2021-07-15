/*
- Problem: https://leetcode.com/problems/valid-triangle-number
*/

#include <iostream>
#include <vector>
#include <algorithm>

int triangleNumber(std::vector<int> nums) {
  if (nums.size() < 3) {
    return 0;
  }

  std::sort(nums.begin(), nums.end());
  int count = 0;
  for (int i = 0; i < nums.size() - 2; i++) {
    for (int j = i+1; j < nums.size() - 1; j++) {
      int right = nums.size()-1, left = j+1;
      int pivot = nums[i] + nums[j];
      while (left<= right) {
        int mid = left + (right - left)/2;
        if (nums[mid] < pivot) {
          left = mid+1;
        } else {
          right = mid - 1;
        }
      }
      count += (right - j);
    }
  }
  return count;
}

int main(void)
{
  std::vector<int> nums = {2,3,4,4};
  std::cout << triangleNumber(nums) << std::endl;
}
