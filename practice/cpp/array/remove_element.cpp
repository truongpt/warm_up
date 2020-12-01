/*
- Problem: https://leetcode.com/explore/learn/card/fun-with-arrays/526/deleting-items-from-an-array/3247/
- Solution:
  - Swap end of current array with needed remove element.
  - Time & space complexity
    - TC : O(n)
    - SC: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& arr, int val)
{
    int l = 0, r = arr.size()-1;
    while (l <= r) {
        if (arr[l] == val) {
            swap(arr[l], arr[r]);
            r--;
        } else {
            l++;
        }
    }

    return r+1;

}

int main(void)
{
    vector<int> arr = {0,1,2,2,3,0,4,2};
    int val = 2;

    int len = removeElement(arr, val);
    for (int i = 0; i < len; i++) {
        cout << arr[i] << ",";
    }
    cout << endl;
}
