/*
- Problem: https://leetcode.com/problems/find-the-most-competitive-subsequence/
- Solution:
  - Greedy with stack,
  - Iteractive each element of input array, check it with last of result string.
    - if smaller and remain element + current result size - 1 >= k -> pop back.
    - if result size small than k -> push back.
  - Time and space complexity
    - TC: O(n)
    - SC: O(k) 
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> mostCompetitive(vector<int>& nums, int k)
{
    vector<int> stack;
    for (int i = 0; i < nums.size(); i++) {
        if (!stack.empty() &&
            nums[i] < stack.back() &&
            stack.size() - 1 + nums.size() - i >= k) {
            stack.pop_back();
        }
        if (stack.size() < k) {
            stack.push_back(nums[i]);
        }
    }
    return stack;
}

int main(void)
{
    vector<int> array = {2,4,3,3,5,4,9,6};
    vector<int> result = mostCompetitive(array, 4);
    for (auto it : result) {
        cout << it << ",";
    }
    cout << endl;
}
