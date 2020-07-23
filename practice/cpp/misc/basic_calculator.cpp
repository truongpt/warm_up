// problem: https://leetcode.com/problems/basic-calculator/
// support only + -

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Sol {
public:
    static int calc(string s) {
        int len = s.length();
        stack<char> op;
        vector<int> val;
        for (int i = 0; i < len; i++) {
            char elem = s[i];
            if ('+' == elem ||
                '-' == elem ||
                '(' == elem) {
                op.push(elem);
            } else if (')' == elem) {
                op.pop();
                if (!op.empty()) {
                    char o = op.top();
                    op.pop();
                    int pos = val.size()-1;
                    val[pos-1] = (o == '+') ? (val[pos-1] + val[pos]):(val[pos-1] - val[pos]);
                    val.pop_back();
                }
            } else {
                int arg = elem - '0';
                int j = i+1;
                for (; j < len; j++) {
                    if (arg >= '0' && arg <= '9') {
                        arg = arg*10 + (s[j]-'0');
                    } else {
                        break;
                    }
                }
                i = j-1;
                if (op.empty() || '(' == op.top()) {
                    val.push_back(arg);
                } else {
                    char o = op.top();
                    op.pop();
                    int pos = val.size()-1;
                    val[pos] = (o == '+') ? (val[pos] + arg):(val[pos] - arg);
                }
            }
        }

        return val[0];
    }
};

int main(int argc, char* argv[])
{
    string s;
    cin >> s;
    cout << s << endl;
    cout << Sol::calc(s) << endl;
    return 0;
}
