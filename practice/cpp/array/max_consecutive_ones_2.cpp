/*
- Problem: https://leetcode.com/explore/learn/card/fun-with-arrays/523/conclusion/3230/  
  ```
  [1,0,1,1,0]
  ```
- Solution 1:
  - Brute force, try flip all zero -> check with is the longest 1 consecutive.

- Solution 2:
  - Calculate all segment number 1.
  - Sliding window to find max 

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMaxConsecutive(vector<int>& arr)
{
    int res = 0;
    bool is_exist_zero = false;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 0) {
            is_exist_zero = true;
            arr[i] = 1;
            int len = 0;
            for (int j = 0; j < arr.size(); j++) {
                len += arr[j];
                if (arr[j] == 0 || j == arr.size()-1) {
                    res = max(res, len);
                    len = 0;
                }
            }
            arr[i] = 0;
        }
    }
    return is_exist_zero ? res  : arr.size();
}

int findMaxConsecutive1(vector<int>& arr)
{
    vector<int> ones = {};
    int num_one = 0;
    for (int i = 0; i < arr.size(); i++) {
        num_one += arr[i];
        if (!arr[i]) {
            ones.push_back(num_one);
            ones.push_back(0);
            num_one = 0;
        }
        if (arr[i] && i == arr.size()-1) {
            ones.push_back(num_one);
        }
    }

    if (ones.size() == 1) {
        return ones[0];
    }

    int max_len = 0;
    int sum = 0;
    int s = 0;
    for (int e = 0; e < ones.size(); e++) {
        sum += ones[e];
        if (e - s >= 3) {
            sum -= ones[s];
            s++;
        }
        max_len = max_len > sum ? max_len : sum;
    }

    return max_len + 1;
}    

int main(void)
{
    {
        vector<int> arr = {1,1,0,1,1,0};
        cout << findMaxConsecutive(arr) << endl;
        cout << findMaxConsecutive1(arr) << endl;
    }

    {
        vector<int> arr = {1,1,0,1};
        cout << findMaxConsecutive(arr) << endl;
        cout << findMaxConsecutive1(arr) << endl;
    }

    {
        vector<int> arr = {1,1};
        cout << findMaxConsecutive(arr) << endl;
        cout << findMaxConsecutive1(arr) << endl;
    }
}
