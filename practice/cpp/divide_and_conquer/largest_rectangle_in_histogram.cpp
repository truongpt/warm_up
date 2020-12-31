/*
- Problem: https://leetcode.com/problems/largest-rectangle-in-histogram/
- Solution:
  - [2,1,5,6,2,3].
       ^
  - Find minimum value element of array -> min value.
  - result = max ( min value * size of array, recursive left side, recursive right side)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMaxArea(vector<int>& heights, int start, int end)
{
    if (start > end) {
        return 0;
    }

    int min_index = start;
    int min_value = heights[min_index];

    for (int i = start; i <= end; i++) {
        if (heights[i] < min_value) {
            min_value = heights[i];
            min_index = i;
        }
    }

    int base_value = min_value * (end - start + 1);

    return max(base_value, max(getMaxArea(heights, start, min_index-1),
                               getMaxArea(heights, min_index+1, end)) );
}

int largestRectangle(vector<int>& heights)
{
    return getMaxArea(heights, 0, heights.size()-1);
}

int main(void)
{
    vector<int> heights = {2,1,5,6,2,3};
    cout << largestRectangle(heights) << endl;
}
