// problem: https://leetcode.com/problems/cheapest-flights-within-k-stops/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    // dijstra
    int findCheapestPriceDi(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;

        unordered_map<int, unordered_map<int,int>> path;
        for (auto f : flights) {
            path[f[0]][f[1]] = f[2];
        }

        q.push({0,src,0});
        while (!q.empty()) {
            vector<int> cur = q.top();
            q.pop();
            if (cur[1] == dst) return cur[0];
            if (cur[2] > K) {continue;}

            for (auto p : path[cur[1]]) {
                int cost = cur[0]+p.second;
                int stop = cur[2]+1;
                q.push({cost, p.first, stop});
            }
        }
        return -1;
    }
    // bellman ford
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> p(K+2, vector<int>(n, INT_MAX/2));
        p[0][src] = 0;
        for (int i = 1; i <= K+1; i++) {
            p[i][src] = 0;
            for (auto f : flights) {
                p[i][f[1]] = min(p[i][f[1]], p[i-1][f[0]] + f[2]);
            }
        }
        return p[K+1][dst] > INT_MAX/2 ? -1 : p[K+1][dst];
    }

    // dfs
    int findCheapestPriceDFS(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> res;
        unordered_map<int, unordered_map<int, int>> m;
        for (auto f : flights) {
            m[f[0]][f[1]] = f[2];
        }
        int cur = 0;
        dfs(m, res, src, dst, cur, K+1);
        int min_p = INT_MAX;
        for (auto r : res) {
            min_p = min(min_p, r);
        }
        return min_p == INT_MAX ? -1 : min_p;
    }

    void dfs(unordered_map<int, unordered_map<int,int>>& m, vector<int>& res, int src, int dst, int cur, int K) {
        if (K < 0) {
            return;
        }
        if (res.size() > 0 && res.back() <= cur) {
            return;
        }
        if (src == dst) {
            res.push_back(cur);
            return;
        }
        for (auto p : m[src]) {
            dfs(m, res, p.first, dst, cur+p.second, K-1);
        }
    }

};

int main(void)
{
    Solution sol;
    int n = 3;
    vector<vector<int>> edges = {{0,1,100},{1,2,100},{0,2,500}};
    int src = 0, dst = 2, k = 1;
    cout << sol.findCheapestPrice(n, edges, src, dst, n) << endl;
    cout << sol.findCheapestPriceDFS(n, edges, src, dst, n) << endl;
    cout << sol.findCheapestPriceDi(n, edges, src, dst, n) << endl;
}
