/*
- Problem: https://leetcode.com/problems/basic-calculator-ii/
  ```
  Input: "3+2*2"
  Output: 7
  ```

- Solution.
  - number -> push stack.
  - * or / -> execute -> push stack.
  - - -> change number -> -number
  - + -> push stack
  - final get all stack -> + 

*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int calculate(string s)
{
    int elem = 0;
    stack<int> num;
    char op = '+';
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c >= '0' && c <= '9') {
            elem = elem*10 +  c - '0';
        }
        
        if ('*' == c ||
            '/' == c ||
            '+' == c ||
            '-' == c ||
            i == s.length()-1) {
            // cout << elem << endl;
            if ('-' == op) {
                num.push(-elem);
            } else if ('+' == op) {
                num.push(elem);
            } else if ('*' == op || '/' == op) {
                int pre = num.top();
                num.pop();
                num.push(('*' == op ? pre * elem : pre / elem));
            }
            elem = 0;
            op = c;
        }
    }

    int res = 0;
    while (!num.empty()) {
        res += num.top();
        num.pop();
    }

    return res;
}

int main(void)
{
    cout << calculate("3-2*2") << endl;
    cout << calculate("3+5 / 2") << endl;
    cout << calculate("3+5 / 222") << endl;

}
