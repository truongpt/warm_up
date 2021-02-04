/*
- Problem: https://leetcode.com/problems/longest-harmonious-subsequence
- Solution:
  - Using hash map (key,value) = (value array, frequenct occur of value)
  - find max value of key + value of (key+1)
  - Time and space complexity
    - TC: O(n)
    - SC: O(n)
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int findLHS(vector<int>& nums)
{
    unordered_map<int,int> m;
    for (auto it : nums) {
        m[it]++;
    }
    int res = 0;

    for (auto it : m) {
        if (m.find(it.first + 1) != m.end()) {
            res = max(res, m[it.first] + m[it.first+1]);
        }
    }

    return res;

}

int main(void)
{
    vector<int> array = {1,2,3,3,3,3,4,5,4,6};
    cout << findLHS(array) << endl;
}
