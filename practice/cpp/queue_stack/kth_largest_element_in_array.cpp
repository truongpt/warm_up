/*
- Problem: https://leetcode.com/problems/kth-largest-element-in-an-array/
- Solution:
  - Using priority queue to maintain list k largest numbers of the array.
  - Time and space complexity
    - TC: O(n * log k)
    - SC: O(k)
*/


#include <iostream>
#include <queue>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    if (nums.size() < k) {
        return -1;
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for (auto it : nums) {
        if (q.size() < k) {
            q.push(it);
        } else {
            if (q.top() < it) {
                q.pop();
                q.push(it);
            }
        }
    }
        
    return q.top();
}

int main(void)
{
    vector<int> nums = {3,2,1,2,3,43,4};
    cout << findKthLargest(nums, 2) << endl;

}
