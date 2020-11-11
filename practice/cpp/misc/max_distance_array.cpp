#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0;
        int min_v = arrays[0][0], max_v = arrays[0].back();
        int len = arrays.size();
        for (int i = 1; i < len; i++) {
            res = max(res, max(arrays[i].back() - min_v, max_v - arrays[i][0]));
            min_v = min(min_v, arrays[i][0]);
            max_v = max(max_v, arrays[i].back());
        }
        
        return res;
    }
};

int main(void)
{
    vector<vector<int>> arrays = {{1,2,3},
                                  {4,5},
                                  {1,2,3}};
    Solution sol;
    cout << sol.maxDistance(arrays) << endl;
    return 0;
}
