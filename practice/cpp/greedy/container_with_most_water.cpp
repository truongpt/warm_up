/*
- Problem: https://leetcode.com/problems/container-with-most-water/
- Solution 1:
  - Brute force with straighforward check all case
  - Time and space complexity.
    - TC: O(n^2)
    - SC: O(1)
- Solution 2:
  - Greedy strategy: Start from largest width, and find next with the colum, 
  which is higher than min of 2 current colum.
  - Time and space complexity.
    - TC: O(n)
    - SC: O(1)
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int maxAreaBrf(vector<int>& height) {
    int res = 0;
    for (int i = 0; i < height.size()-1; i++) {
        for (int j = i+1; j < height.size(); j++) {
            res = max(res,min(height[i],height[j])*(j-i));
        }
    }
        
    return res;
}

int maxAreaGr(vector<int>& height) {
    int l = 0, r = height.size()-1;
    int res = 0;
        
    while (l < r) {
        res = max(res, min(height[l], height[r])*(r-l));
            
        if (height[l] < height[r]) {
            int cur_l = l;
            while (l < r && height[l] <= height[cur_l]) {
                l++;
            }   
        } else {
            int cur_r = r;
            while (r > l && height[r] <= height[cur_r]) {
                r--;
            }
        }
    }
        
    return res;
        
}

int main(void)
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << maxAreaBrf(height) << endl;
    cout << maxAreaGr(height) << endl;
}
