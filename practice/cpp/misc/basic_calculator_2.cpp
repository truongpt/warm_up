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
    int sign = 1;
    string elem = "";
    stack<int> num;
    stack<char> op;
    for (auto it : s) {
        if ('*' == it ||
            '/' == it ||
            '+' == it ||
            '-' == it) {

            if (!elem.empty()) {
                int cur_num = stoi(elem);
                cur_num = sign*cur_num;
                cout << "cur_num:" << cur_num << endl;                 
                if (!op.empty() && (op.top() == '*' || op.top() == '/')) {
                    char cur_op = op.top();
                    op.pop();
                    int pre_num = num.top();
                    num.pop();
                    num.push((cur_op == '*' ? pre_num * cur_num : pre_num / cur_num));
                } else {
                    num.push(cur_num);
                }
                elem = "";
            }

            if ('-' == it) {
                it = '+';
                sign = -1;
            } else {
                sign = 1;
            }
            op.push(it);
        } else if (it >= '0' && it <= '9') {
            elem = elem + it;
        }
    }

    if (!elem.empty()) {
        int cur_num = stoi(elem);
        cur_num = sign*cur_num;
        char cur_op = op.top();

        if (!op.empty() && (op.top() == '*' || op.top() == '/')) {
            char cur_op = op.top();
            op.pop();
            int pre_num = num.top();
            num.pop();
            num.push((cur_op == '*' ? pre_num * cur_num : pre_num / cur_num));
        } else {
            num.push(cur_num);
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
