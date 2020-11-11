// problem: https://leetcode.com/explore/featured/card/september-leetcoding-challenge/557/week-4-september-22nd-september-28th/3474/
// How to resolve by disjoint set?

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef unordered_map<string, unordered_map<string, double>> uud;
typedef unordered_map<string, bool> ub;
typedef vector<vector<string>> vs;

class Solution {
public:
    vector<double> calcEquation(vs& equations, vector<double>& values, vs& queries) {
        uud m;
        ub done;

        for (int i = 0; i < equations.size(); i++) {
            m[equations[i][0]][equations[i][1]] = values[i];
            m[equations[i][1]][equations[i][0]] = 1/values[i];
            done[equations[i][0]] = false;
            done[equations[i][1]] = false;
        }

        vector<double> res;
        for (auto q : queries) {
            res.push_back(dfs(m, done, q[0], q[1]));
        }    

        return res;
    }
    double dfs(uud& m, ub& done, string s, string e) {
        if (m.find(s) == m.end() || m.find(e) == m.end()) {
            return -1;
        }
        if (s == e) {
            return 1.0;
        }

        for (auto it : m[s]) {
            if (done[it.first] == true) continue;
            done[it.first] = true;
            
            double temp = dfs(m, done, it.first, e);
            if (-1.0 != temp) {
                done[it.first] = false;
                return it.second * temp;
            }
            
            done[it.first] = false;
        }
        return -1.0;
    }

};

int main(void)
{

    vs e = {{"a","b"},{"b","c"},{"bc","cd"}};
    vector<double> v = {1.5,2.5,5.0};
    vs q = {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}};

    Solution sol;
    
    vector<double> d = sol.calcEquation(e,v,q);
    for (auto it : d) {
        cout << it << endl;

    }
//   Output: [3.75000,0.40000,5.00000,0.20000]
        
}
