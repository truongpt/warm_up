// problem: https://leetcode.com/problems/distinct-subsequences/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // TopDown.
    // poor performance, resuld on Leetcode
    // Runtime: 1020 ms, faster than 5.04% of C++ online submissions for Distinct Subsequences.
    // Memory Usage: 546.9 MB, less than 5.03% of C++ online submissions for Distinct Subsequences.
    int numDistinctTD(string s, string t) {
        int ls = s.length(), lt = t.length();
        vector<vector<int>> d(ls, vector<int>(lt, -1));
        return numR(s,0,t,0,d);
    }

    int numR(string s, int cs, string t, int ct, vector<vector<int>>& d) {
        int ls = s.length(), lt = t.length();
        if (ct >= lt) {
            return 1;
        }
        if (cs >= ls) {
            return 0;
        }

        if (d[cs][ct] != -1) {
            return d[cs][ct];
        }

        int c1 = 0;
        if (s[cs] == t[ct]) {
            c1 = numR(s,cs+1, t, ct+1, d);
        }
        int c2 = numR(s,cs+1, t, ct, d);

        d[cs][ct] = c1+c2;
        return d[cs][ct];
    }
    // Runtime: 12 ms, faster than 76.98% of C++ online submissions for Distinct Subsequences.
    // Memory Usage: 12.4 MB, less than 41.04% of C++ online submissions for Distinct Subsequences.
    int numDistinctBU(string s, string t) {
        int ls = s.length(), lt = t.length();
        vector<vector<long>> d(lt+1, vector<long>(ls+1, 0));
        for (int j = 0; j <= ls; j++) {
            d[0][j] = 1;
        }
        for (int i = 1; i <= lt; i++) {
            for (int j = 1; j <= ls; j++) {
                d[i][j] = d[i][j-1];
                if (t[i-1] == s[j-1]) {
                    d[i][j] += d[i-1][j-1];
                }
            }
        }

        return (int)d[lt][ls];

    }

};

int main(void)
{
    Solution sol;
    cout << sol.numDistinctTD("rabbbit","rabbit") << endl;
    cout << sol.numDistinctTD("babgbag","bag") << endl;

    cout << sol.numDistinctBU("rabbbit","rabbit") << endl;
    cout << sol.numDistinctBU("babgbag","bag") << endl;
    cout << sol.numDistinctBU("ababab","a") << endl;
    return 0;
}
