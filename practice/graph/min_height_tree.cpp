// problem: https://leetcode.com/problems/minimum-height-trees/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <limits.h>

using namespace std;

class Solution {
public:
    static vector<int> findMinHeightTrees_dfs(int n, vector<vector<int>> &edges)
        {
            // Time Limit Exceed even alot of consider to optimize
            vector<int> h (n,0);
            vector<bool> todo(n, false);
            vector<vector<int>> graph(n, vector<int>{});

            for (auto e : edges) {
                graph[e[1]].push_back(e[0]);
                graph[e[0]].push_back(e[1]);
            }
            int min_height = INT_MAX;
            
            for (int i = 0; i < n; i++) {
                h[i] = dfs(graph, i, todo, min_height);
                min_height = min(min_height, h[i]);
            }

            vector<int> res;

            for (int i = 0; i < n; i++) {
                if (h[i] == min_height) {
                    res.push_back(i);
                }
            }

            return res;
        }

    static int dfs(vector<vector<int>> &graph, int v, vector<bool>& todo, int min_height)
        {
            if (todo[v]) {
                return 0;
            }

            todo[v] = true;
            int max_sub = 0;
            for (auto nv : graph[v]) {
                max_sub = max(max_sub, dfs(graph, nv, todo, min_height));
                if (max_sub >= min_height) {break;}
            }
            todo[v] = false;

            return 1+max_sub;
        }

    // refer idea at: https://leetcode.com/problems/minimum-height-trees/discuss/76055/Share-some-thoughts
    static vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
        {
            vector<unordered_set<int>> g (n, unordered_set<int>{});

            for (auto e : edges) {
                g[e[0]].insert(e[1]);
                g[e[1]].insert(e[0]);
            }

            vector<int> res;

            for (int i = 0; i < n; i++) {
                if (g[i].size() == 1 || g[i].size() == 0 /** for case only 1 vertice*/) {
                    res.push_back(i);
                }
            }

            while (n > 2) {
                n -= res.size();
                vector<int> n_res = {};
                for (auto i : res) {
                    int v = *(g[i].begin());
                    g[v].erase(i);
                    if (g[v].size() == 1) {
                        n_res.push_back(v);
                    }
                }

                res = n_res;
            }

            return res;
        }
    
};

int main(void)
{
    {
        int n = 6;
        vector<vector<int>> edges = {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
        vector<int> res = Solution::findMinHeightTrees(n, edges);
        cout <<"cas 1: " << endl;
        for (auto r : res) {
            cout << r << endl;
        }
    }

    {
        int n = 4;
        vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};
        vector<int> res = Solution::findMinHeightTrees(n, edges);
        cout <<"cas 2: " << endl;
        for (auto r : res) {
            cout << r << endl;
        }
    }

}
