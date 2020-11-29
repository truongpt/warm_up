/*
- Problem: https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/568/week-5-november-29th-november-30th/3548/

- Intuiation.
  - Scan with BFS.

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


bool canReach(vector<int>& arr, int start)
{
    vector<bool> done(arr.size(), false);
    queue<int> q;
    q.push(start);
    done[start] = true;

    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            int cur = q.front();
            q.pop();
            if (arr[cur] == 0) {
                return true;
            }

            if (cur - arr[cur] >= 0 && !done[cur - arr[cur]]) {
                done[cur - arr[cur]] = true;
                q.push(cur - arr[cur]);
            }

            if (cur + arr[cur] < arr.size() && !done[cur + arr[cur]]) {
                done[cur + arr[cur]] = true;
                q.push(cur + arr[cur]);
            }
        }
    }

    return false;
}


int main(void)
{
    vector<int> arr = {4,2,3,0,3,1,2};
    cout << canReach(arr, 5) << endl;

}
