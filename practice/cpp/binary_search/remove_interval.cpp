/*
- Problem: https://leetcode.com/problems/remove-interval/

- Clarify:
  > Input: intervals = [[0,2],[3,4],[5,7]], toBeRemoved = [1,6]
  > Output: [[0,1],[6,7]]
  - toBeRemoved[0] -> find index i
  - toBeRemoved[1] -> find index j
  - if j < i -> do nothing.
  - if j = i -> check intervals[i] with toBeRemoved.
    - case 1 ...
  - if j > i -> check intervals[i], intervals[j] with toBeRemoved
    - case 1 ...
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved)
{
    int l = 0, r = intervals.size()-1;

    int i = -1;

    while (l <= r) {
        int mid = l + (r-l)/2;
        if (toBeRemoved[0] < intervals[mid][0]) {
            r = mid-1;
        } else if (toBeRemoved[0] > intervals[mid][1]) {
            l = mid+1;
        } else {
            i = mid;
            break;
        }
    }

    i = (i == -1) ? l : i;

    l = 0, r = intervals.size()-1;

    int j = -1;

    while (l <= r) {
        int mid = l + (r-l)/2;
        if (toBeRemoved[1] < intervals[mid][0]) {
            r = mid-1;
        } else if (toBeRemoved[1] > intervals[mid][1]) {
            l = mid+1;
        } else {
            j = mid;
            break;
        }
    }

    j = (j == -1) ? r : j;

    if (i >= intervals.size() || j == -1 || j < i) {
        return intervals;
    }

    if (i == j) {
        if (intervals[i][0] < toBeRemoved[0]) {
            int temp = intervals[i][1];
            intervals[i][1] = toBeRemoved[0];
            if (toBeRemoved[1] < temp) {
                intervals.insert(intervals.begin()+i+1, {toBeRemoved[1], temp});
            }
        } else if (toBeRemoved[1] < intervals[i][1]) {
            intervals[i][0] = toBeRemoved[1];
        } else {
            intervals.erase(intervals.begin()+1);
        }
        return intervals;
    } 

    int remove_l = i;
    if (intervals[i][0] < toBeRemoved[0]) {
        intervals[i][1] = toBeRemoved[0];
        remove_l++;
    }

    int remove_r = j;
    if (intervals[j][1] > toBeRemoved[1]) {
        intervals[j][0] = toBeRemoved[1];
        remove_r--;
    }

    if (remove_l <= remove_r) {
        intervals.erase(intervals.begin()+remove_l, intervals.begin()+remove_r+1);
    }

    return intervals;
}

int main(void)
{

}
