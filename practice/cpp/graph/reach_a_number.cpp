/*
- Problem: https://leetcode.com/problems/reach-a-number
- Solution 1:
  - Brute force by BFS
  - Time & space complexity.
    - TC: O(n^2)  Too bad :-(
    - SC: O(n^2)

- Solution 2:
  - https://leetcode.com/problems/reach-a-number/discuss/188999/Throw-Out-All-Fucking-Explanations-This-is-nice-explanation-(c%2B%2B)-I-think-.......
  - By example.
    - target = 3 : 
      - 0 -> 1 -> 3
    - target = 4 : 
      - 0 -> 1 -> 3 -> 6 => 6 - 4 = 2 -> flip 2/2 = 1
      => 0 -> -1 -> 1 -> 4

*/

#include <iostream>
#include <queue>

using namespace std;

int reachNumber(int target) {

    /*node, step*/
    queue<pair<int,int>> q;
    q.push({0,0});
        
    int level = 0;
 
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            pair<int,int> cur = q.front();
            q.pop();
            if (cur.first == target) {
                return level;
            }
            q.push({cur.first + (cur.second+1), cur.second+1});
            q.push({cur.first - (cur.second+1), cur.second+1});
        }
            
        level++;
    }
        
    return -1;
}

int reachNumber2(int target)
{
    int step = 0, sum = 0;
    while (true) {
        if (sum == target) {
            return step;
        } else if (sum > target && (sum-target) % 2 == 0) {
            return step;
        }

        step++;
        sum += step;
    }

    return 0;
}

int main(void)
{
    cout << reachNumber(10) << endl;
    cout << reachNumber(9) << endl;
    cout << reachNumber(100) << endl;

    cout << reachNumber2(10) << endl;
    cout << reachNumber2(9) << endl;
    cout << reachNumber2(100) << endl;

}
