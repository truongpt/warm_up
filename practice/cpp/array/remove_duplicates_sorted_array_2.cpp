/*
- Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
- Solution:
  - Using cnt to store status.
  - TC: O(n)
  - SC: O(1)

*/

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int cnt = 0, cur = 0, pre = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[cur] == nums[i]) {
            if (cnt == 0) {
                cnt++;
                nums[++cur] = nums[i];
            }
        } else {
            nums[++cur] = nums[i];
            cnt = 0;
        }
    }
    return cur+1;
}

int main(void)
{
    vector<int> arr = {1,1,1,1,1,2,2,3,4,4,5,6};
    int n = removeDuplicates(arr);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ",";
    }
    cout << endl;
}

