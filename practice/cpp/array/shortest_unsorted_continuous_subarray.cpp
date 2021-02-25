/*
- Problem: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
- Solution:
  - Find start index of subarray.
    - Find the smallest point, which array is not ascending order.
    - Find min value after the point.
    - Base on the min value -> find start index of subarray.
  - Find end index of subarray.
    - Find the largest point, which array is not ascending order.
    - Find max value before the point.
    - Base on the max value -> find end index of subarray.
  - Time and space complexity.
    - TC: O(n)
    - SC: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

int findUnsortedSubarray(vector<int>& nums) {
    int start = nums.size()-1, end = 0;
    int pivot = -1;
        
    for (int i = 0; i < nums.size(); i++) {
        if (pivot == -1 && (i < nums.size() - 1) && nums[i] > nums[i+1]) {
            pivot = i+1;                
        }
        if (pivot != -1 && nums[i] < nums[pivot]) {
            pivot = i;
        }

    }
        
    for (int j = pivot; j >= 0; j--) {
        if (nums[j] > nums[pivot]) {
            start = j;
        }
    }
        
    pivot = -1;
    for (int i = nums.size()-1; i >= 0; i--) {
        if (pivot == -1 && i > 0 && nums[i] < nums[i-1]) {
            pivot = i-1;
        }
        if (pivot != -1 && nums[i] > nums[pivot]) {
            pivot = i;
        }
    }
        
    for (int j = pivot; j < nums.size(); j++) {
        if (nums[j] < nums[pivot]) {
            end = j;
        }
    }

    if (end > start) {
        return end - start + 1;
    }
        
    return 0;
}

int main(void)
{
    vector<int> arr = {1,3,2,1,1,4};
    cout << findUnsortedSubarray(arr) << endl;
}
