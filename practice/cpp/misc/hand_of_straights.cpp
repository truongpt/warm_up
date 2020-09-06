// problem: https://leetcode.com/problems/hand-of-straights/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    bool isDivice (vector<int> arr, int w)
    {
        if (arr.size() % w) return false;

        map<int,int> s;
        for (auto it : arr) {
            s[it]++;
        }

        while (true) {
            int t = (s.begin())->first;
            for (int i = t; i < t+w; i++) {
                if (s.find(i) != s.end()) {
                    s[i]--;
                    if (0 == s[i]) s.erase(i);
                } else {
                    return false;
                }
            }
            if (s.empty()) {
                return true;
            }
        }
        return false;
    }
};

int main(void)
{
    Solution sol;
    cout << sol.isDivice({1,2,3,3,4,4,5,6}, 4) << endl;
    cout << sol.isDivice({1,2,3,6,2,3,4,7,8}, 3) << endl;
    
}
