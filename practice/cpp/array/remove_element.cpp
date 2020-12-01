/*
- Problem: https://leetcode.com/explore/learn/card/fun-with-arrays/526/deleting-items-from-an-array/3247/
- Solution 1:
  - Swap end of current array with needed remove element.
  - Time & space complexity
    - TC : O(n)
    - SC: O(1)

- Solution 2:
  - If need keep order
*/

#include <iostream>
#include <vector>
using namespace std;

// solution 1
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

// solution 2
int removeElement2(vector<int>& arr, int val)
{
    int i = 0;
    for (int j = 0; j < arr.size(); j++) {
        if (arr[j] != val) {
            arr[i] = arr[j];
            i++;
        }
    }

    return i;
}

int main(void)
{
    vector<int> arr = {0,1,2,2,3,0,4,2};
    int val = 2;

    int len = removeElement2(arr, val);
    for (int i = 0; i < len; i++) {
        cout << arr[i] << ",";
    }
    cout << endl;
}
