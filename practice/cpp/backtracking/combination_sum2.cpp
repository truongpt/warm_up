// problem: https://leetcode.com/problems/combination-sum-ii/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinaSum2(vector<int>& candidates, int target) {
        vector<int> elem = {};
        vector<vector<int>> result = {};
        sort(candidates.begin(), candidates.end());
        findCandidate(candidates, 0, target, elem, result);
        return result;
    }

    void findCandidate(vector<int>& candidates, int index, int target, vector<int> elem, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(elem);
            return;
        }
        if (target < 0 || index > candidates.size()) {
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i-1]) continue;
            elem.push_back(candidates[i]);
            findCandidate(candidates, i+1, target-candidates[i], elem, result);
            elem.pop_back();
        }
        return;
    }
};

int main(void)
{
    {
        vector<int> candidates = {10,1,2,7,6,1,5};
        Solution sol;
        vector<vector<int>> result = sol.combinaSum2(candidates, 8);

        for (auto r : result) {
            for (auto it : r) {
                cout << it << ",";
            }
            cout << endl;
        }
    }

    {
        vector<int> candidates = {1,1,1,1,1};
        Solution sol;
        vector<vector<int>> result = sol.combinaSum2(candidates, 3);

        for (auto r : result) {
            for (auto it : r) {
                cout << it << ",";
            }
            cout << endl;
        }
    }

}



    
