#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int priority(char c)
{
    switch (c){
    case '+':
        cout << "plus" << endl;
        return 1;
        break;
    case '-':
        cout << "minus" << endl;
        return 1;
        break;
    case '*':
        cout << "multi" << endl;
        return 2;
        break;
    case '/':
        cout << "devicor" << endl;
        return 2;
        break;
    case '^':
        return 3;
        break;
    }
}
int is_operator(char c)
{
    if (c != '+' &&
        c != '-' &&
        c != '*' &&
        c != '/') {
        return true;
    } else {
        return false;
    }
}
int is_operand(char c)
{
    if (c != '+' &&
        c != '-' &&
        c != '*' &&
        c != '/' &&
        c != ')' &&
        c != '(') {
        return true;
    } else {
        return false;
    }
}

int main()
{
    int n;
    cin >> n;
    string str = "";
    // priority('+');
    // priority('-');
    // priority('*');
    // priority('/');
    std::stack<char> s;    
    for (int i = 0; i < n; i++) {
        cin >> str;
        vector<char> inf(str.begin(),str.end());
        // scan input string
        for (auto it : inf) {
            cout << it <<" ";
            if (it == '(') {
                s.push(it);
            } else if (it == ')') {
                char t = s.top();
                while (t != '(') {
                    cout << t;
                    t = s.top();
                    s.pop();
                }
                s.pop(); // pop (
            } else if (is_operand(it)) {
                cout<< it;
            } else {
                //operator
                char t = s.top();
                while (true)
                {
                    if (t == '(' ||
                        (is_operator(t) && (priority(it) > priority(t))) ||
                        s.empty()) {
                        break;
                    } else { // need specifix processing for equal?
                        cout << t;
                        s.pop();
                    }
                }
                s.push(it);
            }
        }
    }        
    return 0;
}
