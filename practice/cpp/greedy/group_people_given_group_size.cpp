// problem: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
    // time complexity O(nlogn)
    vector<vector<int>> groupThePeople1(vector<int>& groupSizes)
    {        
        vector<pair<int,int>> g{};
        vector<vector<int>> gp{};

        for (int i = 0; i < groupSizes.size(); i++) {
            g.push_back((pair<int,int>){groupSizes[i],i});
        }

        sort(g.begin(), g.end(), [](auto a, auto b){return a.first < b.first;});

        for (int i = 0; i < g.size(); i++) {
            vector<int> elem{};
            int j = 0;
            for (; j < g[i].first; j++) {
                elem.push_back(g[i+j].second);
            }
            gp.push_back(elem);
            i += (j-1);
        }
        return gp;

    }

    // time complexity O(n)
    vector<vector<int>> groupThePeople(vector<int>& gz)
    {
        vector<vector<int>> res, g(gz.size()+1);
        for (int i = 0; i < gz.size(); i++) {
            g[gz[i]].push_back(i);
            if (g[gz[i]].size() == gz[i]) {
                res.push_back({});
                swap(res.back(), g[gz[i]]);
            
            }
        }
        return res;
    
    }

};

int main(void)
{

    vector<int> groupSizes{3,3,3,3,3,1,3};
    Solution sol;
    vector<vector<int>> res = sol.groupThePeople(groupSizes);
    for (auto r : res) {
        for (auto it : r) {
            cout << it << ",";
        }
        cout << endl;
    }

}
