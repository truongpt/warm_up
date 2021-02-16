/*
- Problem: https://leetcode.com/problems/letter-case-permutation/
- Solution:
  - Thinking as graph problem:
    - if alphabel character, ex 'a' -> connect to 'a' && 'A'
    - Using DFS to scan all cases
  - Time and space complexity.
    - TC: O(2^n) // n is length of input string
    - SC: O(2^n)
*/

#include <iostream>
#include <vector>
using namespace std;

void dfs(string& s, int i, vector<string>& res) {
    if (i >= s.length()) {
        res.push_back(s);
        return;
    }
        
    dfs(s, i+1, res);
    string org = s;
    if (isalpha(s[i])) {
        s[i] ^= (1 << 5);
        dfs(s, i+1, res);
    }
    s = org;
}

vector<string> letterCasePermutation(string S) {
    vector<string> res;
    dfs(S,0,res);

    return res;
}

int main(void)
{
    vector<string> res = letterCasePermutation("1a2d3e");
    for (auto it : res) {
        cout << it << ",";
    }
    cout << endl;
}
