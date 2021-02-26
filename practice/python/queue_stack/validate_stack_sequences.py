'''
- Problem: https://leetcode.com/problems/validate-stack-sequences
- Solution: Using stack to simulate push/pop.
  - when stack top == popped[i] -> pop until
  - after that push more 1 elem to stack
  - Time and space complexity.
    - TC: O(n)
    - SC: O(n) 
'''

def validateStackSequences(pushed: list, popped: list) -> bool:
    stack = []
    N = len(pushed)
    i = 0
    j = 0
    while i < N or j < N:
        while stack:
            if j < N and stack[-1] == popped[j]:
                j += 1
                stack.pop()
            else:
                break
        if i < N:
            stack.append(pushed[i])
            i += 1
        else:
            return not stack
    return not stack

if __name__ == "__main__":
    pushed = [1,2,3,4,5]
    popped = [4,5,3,2,1]
    print(validateStackSequences(pushed, popped))
