/*
- Problem: https://leetcode.com/problems/reach-a-number
- Solution:
  - Brute force by BFS
  - Time & space complexity.
    - TC: O(n^2)  Too bad :-(

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


int main(void)
{
    cout << reachNumber(10) << endl;
    cout << reachNumber(100) << endl;

}
