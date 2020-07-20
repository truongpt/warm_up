#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int priority(char opt)
{
    int p = 0;
    switch (opt)
    {
    case '+':
    case '-':
        p = 0;
        break;
    case '*':
    case '/':
        p = 1;
        break;
    case '^':
        p = 2;
    }
    return p;
}

bool is_opt(char c)
{
    return (c == '+'||c == '-'||c == '*'||c == '/'||c == '^') ? true : false;
}

int main(void)
{
    string s;
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> s;
        vector<char> v(s.begin(), s.end());
        stack<char> st;
        for (auto it : v) {
            if ('(' == it) {
                st.push(it);
            } else if (')' == it) {
                auto ot = st.top();
                st.pop();
                while ('(' != ot) {
                    cout << ot;
                    ot = st.top();
                    st.pop();
                }
            } else if (is_opt(it)) {
                if (st.empty() || st.top() == '(') {
                    st.push(it);
                } else {
                    int cur = priority(it);
                    int pre = priority(st.top());
                    if (cur <= pre) {
                        auto ot = st.top();
                        cout << ot;
                        st.pop();
                    }
                    st.push(it);
                }
            } else {
                cout << it;
            }
        }

        while (!st.empty()) {
            auto ot = st.top();
            cout << ot;
            st.pop();
        }
        cout << endl;
    }
}
