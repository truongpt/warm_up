/*
- Problem: https://leetcode.com/problems/target-sum
*/

#include <iostream>
#include <vector>

int findTargetSumWays(std::vector<int>& nums, int target) {
      
      int offset = 1000;
      int n = nums.size();
      std::vector<std::vector<int>> dp(2001, std::vector<int>(n,0));
    
      dp[nums[0] + offset][0] = 1;
      dp[-nums[0] + offset][0] += 1;

      for (int i = 1; i < n; i++) {
        for (int sum = -offset; sum <= offset; sum++ ) {
            if (dp[sum + offset][i-1]) {
                dp[sum + offset + nums[i]][i] += dp[sum + offset][i-1];
                dp[sum + offset - nums[i]][i] += dp[sum + offset][i-1];
            }
        }
      }
      return dp[offset + target].back();
}

int main(void) {
  std::vector<int> nums = {1,1,1,1,1};  
  std::cout << "result: " << findTargetSumWays(nums, 3) << std::endl;
  return 0;
}
