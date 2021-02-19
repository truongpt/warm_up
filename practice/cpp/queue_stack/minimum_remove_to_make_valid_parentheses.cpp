/*
- Problem: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses
- Solution:
  - Using stack to manage and keep invalid ( or )
  - Base on stack -> remove all invaid char in string.
  - Time and space complexity.
    - TC: O(n)
    - SC: O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

string minRemoveToMakeValid(string s) {
    vector<pair<char, int>> remove_list = {};
        
    // manage remove char
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            remove_list.push_back({s[i],i});
        } else if (s[i] == ')') {
            if (!remove_list.empty() && remove_list.back().first == '(' ) {
                remove_list.pop_back();
            } else {
                remove_list.push_back({s[i],i});
            }
        }
    }
        
    string res;
    int idx = 0;
    // remove
    for (int i = 0; i < s.length(); i++) {
        if (idx < remove_list.size() && remove_list[idx].second == i) {
            idx++;
        } else {
            res += s[i];
        }
    }
        
    return res;
}

int main(void)
{
    cout << minRemoveToMakeValid("l(e(e)t)c)o)de") << endl;
    return 0;
}
