// https://en.wikipedia.org/wiki/Topological_sorting
#include <iostream>
#include <vector>

using namespace std;

class TopologicalSort {
public:
    static vector<int> sort(int v, vector<vector<int>>& edges)
        {
            vector<vector<int>> g (v, vector<int>{});
            vector<int> l(v);
            vector<bool> todo(v, false);
            vector<int> res;
            for (auto e : edges) {
                g[e[0]].push_back(e[1]);
                l[e[1]]++;
            }

            for (int i = 0; i < v; i++) {
                if (l[i]) continue;
                dfs(g, l, todo, res, i);
            }
            return res;
        }

    static void dfs(vector<vector<int>>& g, vector<int>& l, vector<bool>& todo, vector<int>& res, int v)
        {
            if (todo[v]) {
                return;
            }
            if (--l[v] > 0) {
                return;
            }
            res.push_back(v);

            todo[v] = true;
            for (auto s_v : g[v]) {
                dfs(g,l,todo,res,s_v);
            }
            todo[v] = false;
            
        }
};

int main(void)
{
    {
        int v = 4;
        vector<vector<int>> e = {{3, 2}, {3, 0}, {2, 0}, {2, 1}};
        vector<int> res = TopologicalSort::sort(v,e);
        for (auto r : res)
        {
            cout << r << ",";
        }
        cout << endl;
    }
    {
        int v = 5;
        vector<vector<int>> e = {{4, 2}, {4, 3}, {2, 0}, {2, 1}, {3, 1}};
        vector<int> res = TopologicalSort::sort(v,e);
        for (auto r : res)
        {
            cout << r << ",";
        }
        cout << endl;
    }
    {
        int v = 7;
        vector<vector<int>> e = {{6, 4}, {6, 2}, {5, 3}, {5, 4}, {3, 0}, {3, 1}, {3, 2}, {4, 1}};
        vector<int> res = TopologicalSort::sort(v,e);
        for (auto r : res)
        {
            cout << r << ",";
        }
        cout << endl;
    }
}
