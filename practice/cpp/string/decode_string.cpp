/*
- Problem: https://leetcode.com/problems/decode-string
  - Input: s = "3[a]2[bc]"
  - Output: "aaabcbc"

  - Input: s = "3[a2[c]]"
  - Output: "accaccacc"

  - Input: s = "2[abc]3[cd]ef"
  - Output: "abcabccdcdcdef"

- Solution
  - for c : string
    - c != ] -> push stack st.
    - c == ] 
      - get all character untill reach [ -> temp_dec
      - decode number -> num
      - push all charactor of num x temp_dec to stack st.
  - convert all character of stack to result string.    
*/

#include <string>
#include <stack>
#include <iostream>

using namespace std;

string decodeString(string s)
{
    stack<char> st;
    string temp = "";
    int num = 0;
    for (auto c : s) {
        if (c == ']') {
            char t = st.top();
            st.pop();
            temp = "";
            while (t != '[') {
                temp = t+temp;
                t = st.top();
                st.pop();
            }

            t = st.top();
            int i = 1;
            num = 0;
            while (t >= '0' && t <= '9') {
                st.pop();
                num = (t - '0')*i + num;
                i *= 10;
                if (st.empty()) break;
                t = st.top();
            }

            string temp_dec = "";
            for (int i = 0; i < num; i++) {
                temp_dec += temp;
            }

            for (auto b : temp_dec) {
                st.push(b);
            }
            
        } else {
            st.push(c);
        }
    }

    string res;
    while (!st.empty()) {
        char t = st.top();
        st.pop();
        res = t + res;

    }
    return res;
}

int main(void)
{

    cout << decodeString("100[leetcode]") << endl;
    cout << decodeString("3[a2[c]]") << endl;
    cout << decodeString("2[abc]3[cd]ef") << endl;
    cout << decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef") << endl;
    
    return 0;
}
