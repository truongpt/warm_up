/*
- Problem: https://leetcode.com/problems/max-number-of-k-sum-pairs/
- Solution: 
  - Base on problem find sum 2
  - Using map to store k-nums[i] and check remain number is existence in map or not
  - Time and complexity
    - TC: O(n)
    - SC: O(n)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxOperations(vector<int>& nums, int k)
{
    int cnt = 0;
    unordered_map<int,int> m;
    for (auto it : nums) {
        if (m.find(it) != m.end()) {
            cnt++;
            if (--m[it] == 0) {
                m.erase(it);
            }
        } else {
            m[k-it]++;
        }
    }

    return cnt;
}

int main()
{
    vector<int> nums = {3,1,3,3,3};
    int k = 6;
    cout << maxOperations(nums, k) << endl;

}
