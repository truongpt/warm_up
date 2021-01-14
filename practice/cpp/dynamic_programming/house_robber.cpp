/*
- Problem: https://leetcode.com/problems/house-robber/
- Solution:
  - Dynamic programming: d[i] = max(d[i-1],d[i-2] + nums[i])
  - Optimize memory -> O(1)
  - Time and space complexity
    - TC: O(n)
    - SC: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& nums)
{
    if (nums.empty()) {
        return 0;
    }
    int d1 = nums[0];
    int d2 = 0;
    int d = d1;
    for (int i = 1; i < nums.size(); i++) {
        d = max(d1, d2 + nums[i]);
        d2 = d1;
        d1 = d;
    }

    return d;
}

int main(void)
{
    vector<int> nums = {2,7,9,3,1};
    cout << rob(nums) << endl;
}
