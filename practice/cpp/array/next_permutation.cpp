/*
- Problem: https://leetcode.com/problems/next-permutation
- Solution:
  - Following step
    - Find the index, which nums[i] < nums[i+1]
    - find min value from i+1 -> end of array, which min value > nums[i]
    - swap(min value, nums[i])
    - from i+1 to end of array are sorted descrease -> reverse to ascending
      -> make the smallest permutation which is larger than current permutation.
  - Time and space complexity.
    - TC: O(n)
    - SC: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int second = nums.size()-1, first = -1;
    int temp_max = nums.back();
        
    for (int i = nums.size()-2; i >=0; i--) {
        if (nums[i] < temp_max) {
            first = i;
            break;
        }
        if (nums[i] > temp_max) {
            temp_max = nums[i];
            second = i;
        }
    }
        
    if (first >= 0) {        
        for (int i = first+1; i < nums.size(); i++) {
            if (nums[i] > nums[first] && nums[i] <= temp_max) {
                temp_max = nums[i];
                second = i;
            }
        }
        swap(nums[first], nums[second]);
    }        
        
    int l = first+1, r = nums.size()-1;
    while (l < r) {
        swap(nums[l], nums[r]);
        l++,r--;
    }
            
}

int main(void)
{
    vector<int> array = {1,2,2,4,3};
    nextPermutation(array);
    for (auto it : array) {
        cout << it << ",";
    }
    cout << endl;
}
