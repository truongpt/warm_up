/*
- Problem: https://leetcode.com/problems/score-of-parentheses
- Solution1:
  - Using stack to store score of each deep.
  - if  ( -> push 0 to stack
  - if )  -> reduce deep -> pre = pre + max(cur*2,1), pop stack.
  - Time and complexity:
    - TC: O(n)
    - SC: O(n)
- Solution 2:
  - Base on logic: a*(b+c) = a*b + a*c
  - Calculate deep of parentheses.
  - Calculate value of each () by current deep.
  - Time and space complexity.
    - TC: O(n)
    - SC: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

int scoreOfParentheses(string S)
{
    vector<int> score(1,0);
    for (auto c : S) {
        if (c == '(') {
            score.push_back(0);
        } else {
            int cur = score.back();
            score.pop_back();
            int pre = score.back();
            score.pop_back();
            score.push_back(pre + max(cur*2,1));
        }
    }
        
    return score.back();
}

int scoreOfParentheses2(string S)
{
    int res = 0, deep = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '(') {
            deep++;
        } else {
            deep--;
            if (S[i-1] == '(') {
                res += 1 << deep;
            }
        }
    }

    return res;
}

int main(void)
{
    cout << scoreOfParentheses("(()(()))") << endl;
    cout << scoreOfParentheses2("(()(()))") << endl;
}
