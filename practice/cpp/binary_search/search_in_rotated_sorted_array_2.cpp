/*
- Problem: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
  - Input: nums = [2,5,6,0,0,1,2], target = 1
  - Output: true

- Solution 1.
  - Brute force -> scan all elements
  - Time complexity: O(n)
  - Space complexity: O(1)

- Solution 2.
  - Binary search.
  - Issue: having duplicated num -> [2,2,2,2,2,2,2,2,5,6,0,0,1,2,2,2,2,2], target = 1
    - Can not separate with part to continue.
    - Solv -> both of them :-)
  - After fixing above issue -> become no duplicated problem. 
    - l = 0, r = arr.size - 1 -> m = l + (r-l)/2

    - nums = [4,5,6,0,0,1,2,3], target = 1 
                ^
                m
    - nums = [4,5,6,0,0,1,2,3], target = 1 
                          ^
                          m
    - nums = [1,4,5,6,0,0], target = 1 
                  ^
                  m

      - arr[m] > target
        - arr[r] > target 
          - arr[m] > arr[r] -> l = m+1 
          - arr[m] <= arr[r] -> r = m-1 
        - arr[r] < target -> r = m-1

    - nums = [4,5,6,0,0,1,2], target = 2
                    ^
                    m
    - nums = [2,4,5,6,0,0,1], target = 2 
                      ^
                      m
    - nums = [1,2,4,5,6,0,0], target = 4
                ^
                m
      - arr[m] < target
        - arr[l] <= arr[m] -> l = m+1
        - arr[l] > arr[m]
          - arr[l] > target -> l = m+1
          - arr[l] <= target -> r = m-1

- Solution 3.
  - Binary search as solution 2, but approach of solution 2 is too compicated.
  - if first elem == last elem -> search all 2 side part -> change to problem first elem != last elem
  - Solution for first elem != last elem
    - mid = left + (right-left)/2
    - Find not rotated part by comparing mid elem vs first elem.
    - Check target is in non-rotated part by comparing with first and last.
    - Base on compared result -> go to next part.

- Time & Space complexity of binary search.
  - TC: 
    - all elements are duplicated -> the worst case -> O(n)
    - non duplicated -> the best case -> O(log n)
  - SC:
    - all elements are duplicated -> the worst case -> O(log n) for recursion
    - non duplicated -> the best case -> O(1)

*/

#include <iostream>
#include <vector>

using namespace std;

bool searchSub(vector<int>& arr, int target, int l, int r)
{
    if (l > r) return false;
    if (l == r) return arr[l] == target;

    if (arr[l] == arr[r]) {
        return searchSub(arr, target, l, l + (r-l)/2) || searchSub(arr, target, l + 1+ (r-l)/2, r);
    }

    while (l <= r) {
        int m = l + (r-l)/2;
        if (arr[m] == target) {
            return true;
        } else if (arr[m] > target) {
            if (arr[r] < target) {
                r = m-1;
            } else {
                if( arr[m] > arr[r]) {
                    l = m+1;
                } else {
                    r = m-1;
                }
            }
        } else {
            if (arr[l] <= arr[m]) {
                l = m+1;
            } else {
                if (arr[l] > target) {
                    l = m+1;
                } else {
                    r = m-1;
                }
              }
        }
    }

    return false;
}

bool searchSub3(vector<int>& arr, int target, int l, int r)
{
    if (l > r) return false;
    if (l == r) return arr[l] == target;
    if (arr[l] == arr[r]) {
        return searchSub3(arr, target, l, l + (r-l)/2) || searchSub3(arr, target, l + 1+ (r-l)/2, r);
    }

    while (l <= r) {
        int m = l + (r-l)/2;
        if (arr[m] == target) {
            return true;
        } else if (arr[m] >= arr[l]){
            if (arr[l] <= target && target < arr[m]) {
                r = m-1;
            } else {
                l = m+1;
            }
        } else {
            if (arr[m] < target && target <= arr[r]) {
                l = m+1;
            } else {
                r = m-1;
            }
        }
    }

    return false;

}
    
bool search(vector<int>& arr, int target)
{
    return searchSub2(arr, target, 0, arr.size()-1);
}

int main(void)
{
    vector<int> arr = {2,5,6,0,0,1,2,2,2,2,2,2,2};
    cout << search(arr,1) << endl;
}
