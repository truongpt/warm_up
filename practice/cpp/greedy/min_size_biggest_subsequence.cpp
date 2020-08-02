// problem : https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<int> minSubsequence(vector<int>& nums)
        {
            sort(nums.begin(), nums.end(), [](int a, int b) {return a > b;});

            int sum = 0;
            for (auto& num : nums) {
                sum += num;
            }

            vector<int> res;
            int sub_sum = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (sub_sum <= sum) {
                    res.push_back(nums[i]);
                    sum -= nums[i];
                    sub_sum += nums[i];
                }
            }

            return res;
        }
};


int main(void)
{
    {
        Solution sol;
        vector<int> v = {4,3,10,9,8};
        vector<int> res = sol.minSubsequence(v);
        for (auto it : res) {
            cout << it << ",";
        }
        cout << endl;
    }

}
