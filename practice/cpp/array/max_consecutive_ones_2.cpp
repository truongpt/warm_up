/*
- Problem: https://leetcode.com/explore/learn/card/fun-with-arrays/523/conclusion/3230/  
  ```
  [1,0,1,1,0]

  ```
- Solution 1:
  - Brute force, try flip all zero -> check with is the longest 1 consecutive.
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

int main(void)
{
    {
        vector<int> arr = {1,1,0,1,1,0};
        cout << findMaxConsecutive(arr) << endl;
    }

    {
        vector<int> arr = {1,1,0,1};
        cout << findMaxConsecutive(arr) << endl;
    }

    {
        vector<int> arr = {1,1};
        cout << findMaxConsecutive(arr) << endl;
    }
}
