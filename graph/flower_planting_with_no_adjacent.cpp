// problem: https://leetcode.com/problems/flower-planting-with-no-adjacent/

#include <iostream>
#include <vector>

using namespace std;

class GardenNoAdj{
public:
    static vector<int> FlowerPlan(int N, vector<vector<int>>& paths) {
        vector<int> res (N,0);
        
        vector<vector<int>> net (N+1, vector<int>{});
        for (auto p : paths) {
            net[p[0]].push_back(p[1]);
            net[p[1]].push_back(p[0]);
        }
        
        for (int i = 1; i <= N; i++) {            
            if (res[i-1]) continue;
            
            vector<bool> used(5, false);
            for (auto it : net[i]) {
                used[res[it-1]] = true;
            }
            
            for (int j = 1; j <= 4; j++) {
                if (!used[j]) {
                    res[i-1] = j;
                    break;
                }
            }
        }
        
        return res;
    }
};

int main(void)
{
    int N = 3;
    vector<vector<int>> paths = {{1,2},{2,3},{3,1}};
    vector<int> res = GardenNoAdj::FlowerPlan(N,paths);
    for (auto r : res) {
        cout << r <<", ";
    }
    cout << endl;
}
