/*
- Problem: https://leetcode.com/problems/decode-string

Input: s = "3[a]2[bc]"
             ^
Output: "aaabcbc"

Input: s = "3[a2[c]]"
Output: "accaccacc"


Input: s = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef"
zzz                        ^
yypq
jkjk



Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"

*/

#include <string>
#include <stack>
#include <iostream>

using namespace std;


string decodeString(string s)
{
    string res = "";
    stack<int> num;
    stack<string> section;
    string temp = "";
    for (auto c : s) {
        if (c >= '0' && c <= '9') {
            if (!temp.empty()) {
                section.push(temp);
                temp = "";
            }
            int i = c - '0';
            num.push(i);
        } else if (c == ']') {
            int n = num.top();
            num.pop();
            string temp_dec = "";
            for (int i = 0; i < n; i++) {
                temp_dec += temp;
            }

            if (section.empty()) {
                res += temp_dec;
                temp = "";
            } else {
                temp = section.top();
                section.pop();
                temp += temp_dec;
            }
            
        } else if ( c >= 'a' && c <='z') {
            temp = temp+c;
        }
    }
    return res;
}

int main(void)
{
    cout << decodeString("3[a]2[bc]") << endl;
    cout << decodeString("3[a2[c]]") << endl;
    cout << decodeString("2[abc]3[cd]ef") << endl;
    
    return 0;
}
