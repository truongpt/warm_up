/*
- Problem: https://leetcode.com/problems/search-a-2d-matrix-ii
- Solution:
  - Using binary search for row 0 -> find the largest index with matrix[0][r] < target.
  - Using binary search for colum r -> find the smallest index with matrix[t][r] > target.
  - Find from position (r,t)
  - Time and complexity.
    - TC: O(log n + log m + m + n)
    - SC: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
        return false;
    }
        
    int R = matrix.size(), C = matrix[0].size();
        
    // find index at row 0
    int l = 0, r = C-1;
        
    while (l <= r) {
        int m = l + (r-l)/2;
        if (matrix[0][m] == target) {
            return true;
        } else if (matrix[0][m] < target) {
            l = m+1;
        } else {
            r = m-1;
        }
    }
        
    if (r < 0 || r >= C) {
        return false;
    }
        
    // find index at colow with row r
    int t = 0, b = R-1;
        
    while (t <= b) {
        int m = t + (b-t)/2;
        if (matrix[m][r] == target) {
            return true;
        } else if (matrix[m][r] < target) {
            t = m+1;
        } else {
            b = m-1;
        }
    }
        
    // search from postion r & t;        
    while (r >= 0 && r < C && t >= 0 && t < R) {
        if (matrix[t][r] == target) {
            return true;
        } else if (matrix[t][r] < target) {
            t++;
        } else {
            r--;
        }
    }
        
    return false;
        
}

int main(void)
{
    vector<vector<int>> matrix = {{1,4,7,11,15},
                                  {2,5,8,12,19},
                                  {3,6,9,16,22},
                                  {10,13,14,17,24},
                                  {18,21,23,26,30}};
    int target = 5;
    cout << searchMatrix(matrix, target) << endl;

}
