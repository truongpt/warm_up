/*
- Problem: https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/568/week-5-november-29th-november-30th/3547/
- Solution 1
  - Brute force -> find all subarray k -> n
  - Time & space complexity
    - TC: O(n^2)
    - SC: O(1)

*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;


double findMaxAverage(vector<int>& arr, int k)
{
    if (k > arr.size()) {
        return 0.0;
    }

    double max_average = INT_MIN;

    for (int n = k; n <= arr.size(); n++) {
        int sum = 0;
        double average = 0.0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            if (i >= n) {
                sum -= arr[i-n];
            }

            if (i >= n-1) {
                average = static_cast<double>(sum)/static_cast<double>(n);
                // cout << average << endl;
                max_average = max(max_average, average);
            }
        }
    }

    return max_average;
}

int main(void)
{
    vector<int> arr = {8,9,3,1,8,3,0,6,9,2};
    cout << findMaxAverage(arr, 8) << endl;

}
