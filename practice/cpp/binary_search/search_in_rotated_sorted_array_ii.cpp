/*
- Problem: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
  - Input: nums = [2,5,6,0,0,1,2], target = 0
  - Output: true

  - Input: nums = [2,3,5,6,0,0,1,2], target = 3
  - Output: false

- Solution1: Brute force
  - Scan all elements of array
  - Time: O(n)
- Solution2: Binary search
  - l = 0, r = arr.size()-1;
  - m = l + (r-l)/2;
  - arr[m] == target -> ok
  - arr[m] > target
    - nums = [2,5,6,0,0,1,2], target = 0
                ^
      -> l = m+1; arr[m] > arr[r] 
    - nums = [2,5,6,0,0,1,2], target = 0
                        ^
      -> r = m-1
    - nums = [2,2,5,6,0,0,1,2], target = 0
              ^
      -> l = m+1; arr[m] == arr[r] && m != r 
    - nums = [2,5,6,0,0,1,2], target = 0
                          ^
      -> r = m-1; arr[m] == arr[r] && m == r
  - arr[m] < target
    - Input: nums = [2,2,3,5,6,0,0,1,2], target = 3
                               ^
      -> r = m-1; arr[m] < 
    - Input: nums = [2,3,5,6,0,0,1,2], target = 3
                                   ^

    - Input: nums = [2,3,5,6,0,0,1,2], target = 3
                     ^

*/
bool search(vector<int>& arr, int target)
{
    int l = 0, r = arr.size()-1;
    while (l <= r) {
        int m = l + (r-l)/2;
        if (arr[m] == target) {
            return true;
        } else if (arr[m] > target) {
            if (arr[m] >= arr[r] && m != r) {
                l = m+1;
            } else {
                r = m-1;
            }
        } else {

        }
    }
    return false;
}

int main(void)
{


}
