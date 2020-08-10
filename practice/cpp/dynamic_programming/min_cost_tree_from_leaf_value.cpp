// problem: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <climits>

using namespace std;

int minCostTree(vector<int> v)
{
    int n = v.size()-1;
    vector<vector<int>> d(n+1, vector<int>(n+1,0));
    vector<vector<int>> v_max(n+1, vector<int>(n+1,0));

    // build max i,j
    for (int i = 0; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = i; k <= j; k++) {
                v_max[i][j] = max(v_max[i][j], v[k]);
            }
        }
    }

    // calc d[i][j]
    for (int l = 1; l <= n; l++) {
        for (int i = 0; i <= n-l; i++) {
            int j = i+l;
            d[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k+1][j] + v_max[i][k] * v_max[k+1][j]);
            }
        }
    }

    return d[0][n];
}

int main(void)
{
    string s;
    getline(cin, s);
    stringstream ss;
    string o;
    vector<int> v;
    ss << s;
    while (ss >> o) {
        v.push_back(stoi(o));
    }
    cout << minCostTree(v) << endl;
}
