/*
- Problem: https://leetcode.com/problems/simplify-path
- Solution:
  - Using stack to manage folder when scan original path.
  - Separate string with / and / -> cur string
    - if cur is folder -> push to stack.
    - if cur is . -> do nothing
    - if cur is .. -> pop last element of stack.
  - Time and space complexibility.
    - TC: O(n)
    - SC: O(n)
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string simplifyPath(string path) {
    vector<string> res = {};        
    string cur = "";
    char c;

    for (int i = 0; i <= path.length(); i++) {
        if (i != path.length()) {
            c = path[i];
        }
        if (c == '/' || i == path.length()) {
            if (cur == ".") {
                cur = "";
            } else if (cur == "..") {
                if (!res.empty()) res.pop_back();
                cur = "";
            } else if (cur == "" || cur == "/") {
                    
            } else {
                res.push_back(cur);
                cur = "";
            }
        } else {
            cur += c;
        }
    }
        
    if (res.empty()) {
        return "/";
    }

    string ans = "";
    for (auto it : res) {
        ans += "/" + it;
    }
        
    return ans;
}

int main(void)
{
    cout << simplifyPath("/a/b/../c/d/e/..") << endl;
}
