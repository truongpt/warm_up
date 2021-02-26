/*
- Problem: https://leetcode.com/problems/wiggle-subsequence
- Solution:
  - len[i] -> store max len wiggle subsequence from 0 -> i
  - d[i] -> store sign of nums[i] with previous element.
  - len[i] = max(len[i], len[j]+1) with j = i-1 -> 0 and condition (nums[i] - nums[j])*d[j] < 0
  - Time and space complexity.
    - TC: O(n^2)
    - SC: O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

int wiggleMaxLength(vector<int>& nums) {
    if (nums.size() < 2) {
        return nums.size();
    }
        
    vector<int> d = vector<int>(nums.size(), 0);
    vector<int> len = vector<int>(nums.size(), 1);
        
    for (int i = 1; i < nums.size(); i++) {
        for (int j = i-1; j >= 0; j--) {
            if ((nums[i] - nums[j])*d[j] < 0 || (j == 0 && nums[i] - nums[j] != 0) ) {
                if (len[i] < len[j]+1) {
                    len[i] = len[j] + 1;
                    d[i] = (nums[i] - nums[j] > 0 ? 1 : -1);
                }
            }
        }
    }
    return len.back();
}

int main(void)
{
    vector<int> arr = {1,17,5,10,13,15,10,5,16,8};
    cout << wiggleMaxLength(arr) << endl;
}
