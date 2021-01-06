/*
- Problem: https://leetcode.com/problems/kth-missing-positive-number
- Solution:
*/

#include <iostream>
#include <vector>
using namespace std;

// Brute force
int findKthPositive1(vector<int>& arr, int k) {
    int order = 0;
    int val = 1;
    int i = 0;
    while (order < k) {
        if (i < arr.size() && val == arr[i]) {
            i++;
            val++;
        } else {
            val++;
            order++;
        }
    }
        
    return --val;
}

// binary search
int findKthPositive(vector<int>& arr, int k) {
    int l = 0, r = arr.size()-1;
    while (l <= r) {
        int m = l + (r-l)/2;
        if (arr[m] - m - 1 < k) {
            l = m+1;
        } else {
            r = m-1;
        }
    }
        
    return l+k;
}

int main()
{
    vector<int> arr = {2,3,4,7,9,10};
    cout << findKthPositive(arr, 10) << endl;
}
