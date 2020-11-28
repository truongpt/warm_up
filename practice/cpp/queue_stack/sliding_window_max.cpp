/*
- Problem: https://leetcode.com/problems/sliding-window-maximum/

- Intuition.
  - Use map -> that will be ascending order.

- Curiously
  - What diff map<> vs unordered_map<>

*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    map<int,int> m;
    vector<int> res = {};
    for (int i = 0; i < nums.size(); i++) {
        m[nums[i]]++;
        if (i >= k-1) {
            auto local_max = (--m.end())->first;
            res.push_back(local_max);
            m[nums[i-k+1]]--;
            if (m[nums[i-k+1]] == 0) {
                m.erase(nums[i-k+1]);
            }
        }
    }
        
    return res;
}

int main(void)
{
    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    vector<int> res = maxSlidingWindow(arr,3);
    for (auto it :  res) {
        cout << it << ",";
    }
    cout << endl;
}
