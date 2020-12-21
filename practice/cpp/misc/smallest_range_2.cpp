/*
- Problem: https://leetcode.com/problems/smallest-range-ii/
- Solution:
  - if add all K value to B -> result is not change.
  - Problem is changed to add or not add 2*K to A
  - Sort A.
  - Start from index = 0, add each elem 2*K, update diff of max - min
    - max value = max (A[n-1], A[i] + 2*K)
    - min value = min (A[i+1], A[0] + 2*K)
  - Time and space complexity:
    - TC: O(n log n)
    - SC: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int smallestRange(vector<int>& arr, int k)
{
    if (arr.empty()) {
        return 0;
    }
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int max_value = arr[n-1], min_value = arr[0];
    int res = max_value - min_value;

    for (int i = 0; i < n-1; i++) {
        max_value = max(max_value, arr[i] + 2*k);
        min_value = min(arr[0]+2*k, arr[i+1]);
        res = min(res, max_value -  min_value);
    }

    return res;
}

int main(void)
{
    vector<int> arr = {1,3,6};
    cout << smallestRange(arr, 3) << endl;
}
