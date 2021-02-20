'''
- Problem: https://leetcode.com/problems/valid-parentheses/
- Solution:
  - Using stack to check current character with previous character.
    - if conflict with rule valid parentheses -> return false.
    - if OK -> remove this pair.
  - Time and space complexity.
    - TC: O(n)
    - SC: O(n)

'''

def isValid(s: str) -> bool:
    m = {')':'(', '}': '{', ']':'['}        
    store = list()
    for c in s:
        if c == '(' or c == '{' or c == '[':
            store.append(c)
        else:
            if store[-1] == m.get(c):
                store.pop()
            else:
                return False
    return len(store) == 0

if __name__ == "__main__":
    s = "()()"
    print(isValid(s))
