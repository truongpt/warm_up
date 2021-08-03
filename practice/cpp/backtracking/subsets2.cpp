/*
- Problem:
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

void subsetCreate(std::vector<std::vector<int>>& res, std::unordered_map<int,int> pre, int cur, std::vector<int>& nums) {
  if (cur >= nums.size()) {
    return;
  }

  int start = 0;
  int end = res.size()-1;
  if (pre.find(nums[cur]) != pre.end()) {
    start = end - pre[nums[cur]] + 1;
  } else {
    pre[nums[cur]] = res.size();
  }
        
  for (int i = start; i <= end; i++) {
    auto add = res[i];
    add.push_back(nums[cur]);
    res.push_back(add);
  }
  subsetCreate(res, pre, cur+1, nums);
}

std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end());
  std::vector<std::vector<int>> res{{}};
  std::unordered_map<int,int> pre;
  subsetCreate(res, pre, 0, nums);
  return res;
}

int main(void) {
  std::vector<int> nums = {1,2,2};
  auto res = subsetsWithDup(nums);

  for (auto v : res) {
    for (auto elem : v) {
      std::cout << elem << ",";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
