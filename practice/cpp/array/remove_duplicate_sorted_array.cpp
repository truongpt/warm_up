/*
- Problem: https://leetcode.com/explore/learn/card/fun-with-arrays/526/deleting-items-from-an-array/3248/
- Solution:
  - One pass
  - TC: O(n)
  - SC: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
    /*
    [0,1,1,1,1,2,2,3,3,4]
       ^       ^
       i       j
    */
    int i = -1;
    for (int j = 0; j < nums.size(); j++) {
        if (-1 == i || nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }

    return i+1;
}

int main(void)
{
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int len = removeDuplicates(nums);
    for (int i = 0; i < len; i++) {
        cout << nums[i] << ",";
    }
    cout << endl;
}
