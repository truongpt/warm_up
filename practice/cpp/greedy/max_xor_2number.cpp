// problem: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findMaxXor(vector<int> nums) {
        int max_result = 0;
        int cur_xor = 0;
        unordered_set<int> s;

        for (int i = 31; i >=0; i--) {
            max_result <<= 1;
            cur_xor = max_result | 1;
            s.clear();
            for (auto num : nums) {
                s.insert(num >> i);
            }
            for (auto elem : s) {
                if (s.find(elem ^ cur_xor) != s.end()) {
                    max_result = cur_xor;
                    break;
                }
            }
        }
        return max_result;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {3, 10, 5, 25, 2, 8};
    cout << sol.findMaxXor(v) << endl;
}
