// problem: https://leetcode.com/problems/graph-valid-tree/
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    static bool validTree(int n, vector<vector<int>>& edges)
        {
            vector<vector<int>> graph(n, vector<int>{});
            vector<bool> done(n, false);
            vector<bool> todo(n, false);
            for (auto e : edges) {
                graph[e[0]].push_back(e[1]);
                graph[e[1]].push_back(e[0]);
            }

            if (!dfs(graph, 0, todo, done)) {
                return false;
            }

            for (auto b : done) {
                if (!b) return false;
            }
            return true;
        }
    static bool dfs(vector<vector<int>>& graph, int v, vector<bool>& todo, vector<bool>& done)
        {
            if (todo[v]) {
                return true;
            }
            if (done[v]) {
                return false;
            }
            done[v] =  true;

            todo[v] = true;
            for (auto a : graph[v]) {
                if (!dfs(graph, a, todo, done)) {
                    return false;
                }
            }
            todo[v] = false;
            return true;
        }
};


int main(void)
{
    {
        int n = 5;
        vector<vector<int>> edges = {{0,1}, {0,2}, {0,3}, {1,4}};
        cout << Solution::validTree(n, edges) << endl;
    }
    {
        int n = 5;
        vector<vector<int>> edges = {{0,1}, {1,2}, {2,3}, {1,3}, {1,4}};
        cout << Solution::validTree(n, edges) << endl;
    }
    
}
