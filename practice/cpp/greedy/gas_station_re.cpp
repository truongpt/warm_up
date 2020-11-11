#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canComplete(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < gas.size(); i++) {
            cost[i] = gas[i] - cost[i];
        }

        for (int i = 0; i < n ; i++) {
            if (cost[i] < 0) continue;
            int start = i;
            int cur = cost[i];
            while (true) {
                i = ++i % n;
                cur += cost[i];
                if (cur < 0) {
                    cur = 0;
                    break;
                } else if (i == start) {
                    return start;
                }
            }
            if (i < start) return -1;
        }
        return -1;
    }
};

int main() {
    vector<int> gas = {1,  2, 3, 4,5};
    vector<int> cost = {3,  4, 5, 1,2};
    Solution sol;
    cout << sol.canComplete(gas, cost) << endl;

}
