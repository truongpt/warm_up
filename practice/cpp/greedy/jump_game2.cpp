// problem: https://leetcode.com/problems/jump-game-ii/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
    public:
        int jump(vector<int>& j)
        {
            int index = j.size()-1;
            int step = 0;
            while (index != 0) {
                int next_index = index;
                for (int i = index; i > 0; i--) {
                    if (j[index-i] >= i) {
                        next_index = index - i;
                        break;
                    }
                }
                step++;
                index = next_index;
            }
            return step;
        }
}        
;

int main(void)
{
    Solution sol;
    vector<int> j = {2,3,1,1,4};
    //string j_str;

    cout << "min step: " << sol.jump(j) << endl;
    return 0;

}
