/*
- Problem: https://leetcode.com/problems/check-array-formation-through-concatenation
- Solution:
  - Key point is all value of input array is distint
  - Base on first element of each array in pieces to find which array element in pieces is valid.
  - Time & space complexity.
    - TC: O(N)
    - SC: O(N)
*/

#include <iostream>
#include <vector>
using namespace std;

bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    vector<int> first (101, -1);
    for (int i = 0; i < pieces.size(); i++) {
        first[pieces[i][0]] = i;
    }
        
    for (int i = 0; i < arr.size(); ) {
        int idx = first[arr[i]];
        if (idx == -1) {
            return false;
        }
        for (int j = 0; j < pieces[idx].size(); j++) {
            if (pieces[idx][j] != arr[i++]) {
                return false;
            }
        }
    }
        
    return true;
}


int main(void)
{
    vector<int> arr = {91,4,64,78};
    vector<vector<int>> pieces = {{78},{4,64},{91}};
    cout << canFormArray(arr, pieces) << endl;
}
