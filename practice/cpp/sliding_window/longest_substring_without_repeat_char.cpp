/*
- Problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/
- Solution:
  - Sliding windows.
  - if detect repeat char -> set start = last position of repeated character + 1
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    vector<int> m(27, -1);
    int len = 0;
    int start = 0;

    for (int i = 0; i < s.length(); i++) {
        if (m[s[i] - 'a'] >= start) {
            start = m[s[i] - 'a'] + 1;
        }
        m[s[i] - 'a'] = i;
        len = max(len, i - start + 1);
    }

    return len;
}

int main(void)
{
    cout << lengthOfLongestSubstring("abcbbaa") << endl;
    cout << lengthOfLongestSubstring("bbbbb") << endl;
}
