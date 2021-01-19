/*
- Problem: https://leetcode.com/problems/longest-palindromic-substring
- Solution:
  - Dynamic programming bottom up
    d[i][j] = d[i-1][j+1] + 2
  - Time and space complexity
    - TC: O(n^2)
    - SC: O(n^2) 
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestPalindrome(string s)
{
    int N = s.length();
    vector<vector<int>> d(N, vector<int>(N,0));
    for (int i = 0; i < N; i++) {
        d[i][i] = 1;
    }
        
    int max_len = 1;
    int f = 0, e = 0;
    for (int i = N-2; i >= 0; i--) {
        for (int j = i+1; j < N; j++) {
            if (s[i] == s[j]) {
                if (j == i+1) {
                    d[j][i] = 2;
                } else if(d[j-1][i+1] != 0) {
                    d[j][i] = d[j-1][i+1]+2;
                }
            }
                

            if (d[j][i] > max_len) {
                f = i, e = j;
                max_len = d[j][i];
            }
        }
    }

    return s.substr(f, e-f+1);        
}

int main(void)
{
    cout << longestPalindrome("abcdde") << endl;
}
