// problem: https://leetcode.com/problems/gas-station/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int startStation(vector<int> gas, vector<int> cost)
        {
            int total = 0, cur = 0, start = 0;
            for (int i = 0; i < gas.size(); i++) {
                total += (gas[i] - cost[i]);
                cur += (gas[i] - cost[i]);
                if (cur < 0) {
                    start = i+1;
                    cur = 0;
                }
            }
            return (total < 0) ? -1 : start;
        }
};

int main(void)
{
    Solution sol;
    cout << sol.startStation({1,2,3,4,5},{3,4,5,1,2}) << endl;
    return 0;
}
