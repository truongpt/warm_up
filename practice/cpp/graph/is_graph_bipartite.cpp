/*
  - Problem: https://leetcode.com/problems/is-graph-bipartite/
  - Solution:
  - BSF scan all graph, and mark group ID of each layer.
  - If 2 node adjacent is same group ID -> false.
  - Note the graph can be disconnect -> need care this case.
  - Time and space complexity.
  - TC: O(n)
  - SC: O(n)
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
        
    int N = graph.size();
    vector<int> group(N,-1);
        
    unordered_set<int> s;
        
    for (int i = 1; i < N; i++) {
        s.insert(i);
    }
        
    queue<int> q;
    q.push(0);
    group[0] = 0;
        
    while (!q.empty() || !s.empty()) {
        if (q.empty()) {
            int next = *(s.begin());
            q.push(next);
            group[next] = 0;
            s.erase(next);
        }
            
        int cur = q.front();
        q.pop();
            
        for (auto it : graph[cur]) {
            if (group[it] == -1) {
                group[it] = 1 - group[cur];
                q.push(it);
                s.erase(it);
            } else if (group[it] != 1-group[cur]) {
                return false;
            }
        }
    }
        
    return true;
        
}

int main(void)
{
    vector<vector<int>> graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
    cout << isBipartite(graph) << endl;

}
