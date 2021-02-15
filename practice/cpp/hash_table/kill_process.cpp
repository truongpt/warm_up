/*
- Problem: https://leetcode.com/problems/kill-process
- Solution:
  - Using hash map to map delete value with index
  - Update delete list until it become empty.
  - Time and space complexity.
    - TC: O(n)
    - SC: O(n)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill)
{
    unordered_map<int,vector<int>> m;
    for (int i = 0; i < ppid.size(); i++) {
        m[ppid[i]].push_back(i);
    }
        
    vector<int> d = {};
    vector<int> res = {};
    d.push_back(kill);
        
        
    while (!d.empty()) {
        int cur = d.back();
        d.pop_back();
        res.push_back(cur);
            
        for (auto it : m[cur]) {
            d.push_back(pid[it]);
        }
            
    }        
    return res;
}

int main(void)
{
    vector<int> pid = {1, 3, 10, 5};
    vector<int> ppid = {3, 0, 5, 3};
    int kill = 5;
    
    vector<int> res = killProcess(pid, ppid, kill);
    for (auto it : res) {
        cout << it << ",";
    }
    cout << endl;
}
