// problem: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3447/
#include <iostream>
#include <string>

// wtf, how to improve to O(n)
using namespace std;

class Solution{
public:
  bool repeatedSubstringPattern(string s)
  {
    int len = s.length();
    if (0 == len) return false;
    
    for (int i = 1; i <= len/2; i++) {
      if (len % i) {
        continue;
      }
      string p = s.substr(0,i);
      int j = 0;
      for (j = i; j < len; j += i) {
        string q = s.substr(j,i);
        if (q != p) {
           break;
        }
      }
      if (j == len) {
        return true;
      }
    }
    return false;
  }
};

int main(void)
{
  Solution sol;
  cout << sol.repeatedSubstringPattern("abab") << endl;
  cout << sol.repeatedSubstringPattern("aba") << endl;
  cout << sol.repeatedSubstringPattern("aa") << endl;
  cout << sol.repeatedSubstringPattern("a") << endl;
}
