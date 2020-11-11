// problem: https://leetcode.com/problems/combination-sum/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res = {};
        vector<int> elem = {};
        backtrack(candidates, target, res, elem);
        return res;
    }

    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int> elem) {
        if (0 == target) {
            res.push_back(elem);
            return;
        } else if (0 > target) {
            return;
        }
        for (auto num : candidates) {
            if (!elem.empty() && num < elem.back()) {
                continue;
            }
            elem.push_back(num);
            backtrack(candidates, target - num, res, elem);
            elem.pop_back();
        }
    }
};

int main(void)
{
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    Solution sol;
    vector<vector<int>> res = sol.combinationSum(candidates, target);
    for (auto v : res) {
        for (auto n : v) {
            cout << n << ",";
        }
        cout << endl;
    }
}

