/*
- Problem: https://leetcode.com/problems/palindromic-substrings
- Solution:
  - i,j is position in the string, substring from i->j is palindromic
  when s[i] == s[j] && i+1 -> j-1 also palindromic.
  - Dynamic problem bottom up.
*/

#include <iostream>
#include <vector>
using namespace std;

int countSubstrings(string s) {
    int N = s.length();
    vector<vector<bool>> p(N, vector<bool>(N, false));
        
    int cnt = N;
    for (int i = 0; i < N; i++) {
        p[i][i] = true;
    }
        
        
    for (int i = N-1; i >= 0; i--) {
        for (int  j = i+1; j < N; j++) {
            if ((j == i+1 && s[i] == s[j]) || (p[i+1][j-1] && s[i] == s[j])) {
                p[i][j] = true;
                cnt++;
            }
        }
            
            
    }
        
    return cnt;
        
}

int main(int argc, char** args)
{
    std::cout << countSubstrings("aba") << std::endl;
}
