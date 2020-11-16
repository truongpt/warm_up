/*
- Problem: https://leetcode.com/problems/longest-mountain-in-array/

- Solution:
  - Input: [2,1,4,7,3,2,5]
              ^       ^
             start    end
              
  - Straightforward count left side + right side

- Reference
  - https://leetcode.com/problems/longest-mountain-in-array/discuss/135593/C%2B%2BJavaPython-1-pass-and-O(1)-space

*/

#include <iostream>
#include <vector>
using namespace std;

int getLongestMountain(vector<int>& arr)
{
    int arr_size = arr.size();
    int cnt = -1;

    int start = 0, end = 0;
    int res = 0;

    while (start < arr.size()) {
        end = start;
        if (end < arr_size-1 && arr[end] < arr[end+1]) {
            while (end < arr_size-1 && arr[end] < arr[end+1]) {
                end++;
            }

            // confirm that is top
            if (end < arr_size-1 && arr[end] > arr[end+1]) {
                while (end < arr_size-1 && arr[end] > arr[end+1]) {
                    end++;
                    res = max(res, end-start+1);
                }
            }
        }
        start = max(start+1, end);
    }
    return res;
}

int main()
{
    {
        vector<int> arr = {2,1,4,7,3,2,5};
        cout << getLongestMountain(arr) << endl;
    }
    {
        vector<int> arr = {0,1,4,7,3,2,1};
        cout << getLongestMountain(arr) << endl;
    }
    {
        vector<int> arr = {1,2,3};
        cout << getLongestMountain(arr) << endl;
    }
    return 0;
}
