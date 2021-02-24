'''
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
'''

def scoreOfParentheses(S: str) -> int:
    score = [0]
    for c in S:
        if c == '(':
            score.append(0)
        else:
            cur = score.pop()
            pre = score.pop()
            score.append(pre + max(cur*2,1))
    return score[0]

def scoreOfParentheses2(S: str) -> int:
    res = 0
    deep = 0

    for i in range(len(S)):
        if S[i] == '(':
            deep += 1
        else:
            deep -= 1
            if (S[i-1] == '('):
                res += 1 << deep
    return res
                
if __name__ == "__main__":
    print(scoreOfParentheses("(()(()))"))
    print(scoreOfParentheses2("(()(()))"))
