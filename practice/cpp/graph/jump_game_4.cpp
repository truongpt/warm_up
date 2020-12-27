/*
- Problem: https://leetcode.com/problems/jump-game-iv/
- Solution:
  - Graph problem.
  - Create edge matrix
  - BFS to find the shorted path
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int minJump(vector<int>& arr)
{
    unordered_map<int, vector<int>> edge;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        edge[arr[i]].push_back(i);
    }

    vector<bool> done(n, false);
    queue<int> q;
    q.push(0);
    int jump = 0;

    while (!q.empty()) {
        int num = q.size();
        for (int i = 0; i < num; i++) {
            int cur = q.front();
            if (cur == n-1) {
                return jump;
            }
            q.pop();
            done[cur] = true;

            if (cur > 0 && !done[cur-1]) {
                q.push(cur-1);
            }

            if (!done[cur+1]) {
                q.push(cur+1);
            }

            for (auto it : edge[arr[cur]]) {
                if (!done[it] && it != cur) {
                    q.push(it);
                }
            }
            // clear to avoid duplicate -> Important point to improve performance.
            edge[arr[cur]].clear();
        }
        jump++;
    }

    return jump;
}

int main()
{
    vector<int> arr = {100,-23,-23,404,100,23,23,23,3,404};
    cout << minJump(arr) << endl;


}
