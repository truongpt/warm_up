/*
- Problem: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix
- Solution: -> TODO: Need improve performance.
  - Time and space complexity.
    - TC: O(m*n)
    - TC: O(m*k)
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

auto comp = [](pair<int,int> a, pair<int,int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
};

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
    vector<pair<int,int>> row = {};
        
    for (int i = 0; i < mat.size(); i++) {
        int elem = 0;
        for (auto it : mat[i]) {
            if (it == 0) {
                break;
            }
            elem += it;
        }
        row.push_back({elem, i});
    }
        
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> q(comp);
        
    for (auto it : row) {
        if (q.size() < k) {
            q.push(it);
        } else {
            auto cur_top = q.top();
            if (it.first < cur_top.first || 
                (it.first == cur_top.first && it.second < cur_top.second) ) {
                q.pop();
                q.push(it);
            }
        }
    }
        
    vector<int> res;
    while (!q.empty()) {
        auto cur_top = q.top();
        q.pop();
        res.push_back(cur_top.second);
    }
    reverse(res.begin(), res.end());
        
    return res;
        
}

int main(void)
{
    vector<vector<int>> mat = {{1,1,0,0,0},
                               {1,1,1,1,0},
                               {1,0,0,0,0},
                               {1,1,0,0,0},
                               {1,1,1,1,1}};
    vector<int> res = kWeakestRows(mat, 3);

    for (auto it : res) {
        cout << it << ",";
    }
    cout << endl;    
}
