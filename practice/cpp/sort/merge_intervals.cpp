/*
- Problem: https://leetcode.com/problems/merge-intervals/

- Solution.
  - Sort ascending.
  - Check arr[pivot][1] vs arr[i][0]
    - [[1,3],[2,6],[8,10],[15,18]]
        ^      ^
       pivot   i
    - arr[pivot][1] > arr[i][0] -> arr[pivot][1] = max(arr[pivot][1], arr[i][1])
    - arr[pivot][1] < arr[i][0] -> pivot++, arr[pivot] = arr[i]
  - Time & memory.
    - TC: O(n log n)
    - SC: O(1)

*/

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals)
{

    sort(intervals.begin(), intervals.end());
    int pivot = 0;

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[pivot][1] >= intervals[i][0]) {
            intervals[pivot][1] = max(intervals[pivot][1], intervals[i][1]);
        } else {
            intervals[++pivot] = intervals[i];
        }
    }
    if (pivot < intervals.size()-1) {
        intervals.erase(intervals.begin() + pivot + 1, intervals.end());
    }
    return intervals;    
}
