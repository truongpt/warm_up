// problem:

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int removeCoverInterval(vector<vector<int>>& interval) {
        sort(interval.begin(), interval.end(), [](auto a, auto b){return a[0] < b[0];});

        int cnt = interval.size();
        int pos = 0;
        for (int i = 1; i < interval.size(); i++) {
            if (interval[pos][1] >= interval[i][1]) {
                cnt--;
            } else {
                pos = i;
            }
        }
        return cnt;
    }
};

int main(void)
{
    vector<vector<int>> v = {{1,4},{3,6},{2,8}};
    Solution sol;
    cout << sol.removeCoverInterval(v) << endl;
  
}

