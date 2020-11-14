/*
- Problem: https://leetcode.com/problems/median-of-two-sorted-arrays/

- Clarify
  - What is median of array?
    - Divice array to 2 sub array  A & B, size A  == size B, all elemments of A not greater than B
    - return (max elem A + min elem B) /2
  - Median of sorted array?
    - if sizeof (array) is odd -> return array[size of array/2]
    - if sizeof (array) is even -> return (array[size of array/2] + array[size of array/2 - 1])/2

- Solution1
  - Merger to one array -> get median
  - TC: O(m+n)
  - SC: O(m+n)

- Solution2
  - Binary search on 2 sorted array.
  - TC: O(log (m+n))
  - SC: O(1)

- Reference
  - https://medium.com/@hazemu/finding-the-median-of-2-sorted-arrays-in-logarithmic-time-1d3f2ecbeb46
  - https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2471/Very-concise-O(log(min(MN)))-iterative-solution-with-detailed-explanation

*/

#include <iostream>
#include <vector>
using namespace std;

double getMedianOfTwoSortedArraysS1(vector<int> arr1, vector<int> arr2)
{
    // do later
    return 0.0;
}

double getMedianOfTwoSortedArraysS2(vector<int> arr1, vector<int> arr2)
{
    if (arr2.size() < arr1.size()) {
        return getMedianOfTwoSortedArraysS2(arr2, arr1);
    }

    int l = 0, r = arr1.size();
    int n = arr1.size(), m = arr2.size();
    int i,j;

    while (l <= r) {
        i = l + (r-l)/2;
        j = (m+n+1)/2 - i;

        if (i < r && arr2[j-1] > arr1[i]) {
            l = i+1;
        } else if (i > l && arr1[i-1] < arr2[j]) {
            r = i-1;
        } else {
            int max_left = 0;
            if (i == 0) {
                max_left = arr2[j-1];
            } else if (j == 0) {
                max_left = arr1[i-1];
            } else {
                max_left = max(arr1[i-1], arr2[j-1]);
            }
            if ((m+n) % 2) return max_left;
          
            int min_right = 0;
            if (i == n) {
                min_right = arr2[j];
            } else if (j == m) {
                min_right = arr1[i];
            } else {
                min_right = min(arr1[i], arr2[j]);
            }
            return (static_cast<double>(min_right) + static_cast<double>(max_left))/2;
        }

    }

    return 0.0;
}

int main(void)
{
    vector<int> arr1 = {1,2};
    vector<int> arr2 = {3,4};
    
    cout << getMedianOfTwoSortedArraysS2(arr1, arr2) << endl;
}
