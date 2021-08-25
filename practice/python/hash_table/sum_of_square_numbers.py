"""
- Problem: https://leetcode.com/problems/sum-of-square-numbers/
"""

def judgeSquareSum(c):
    s = set()
    for i in range(c+1):
        if i*i <= c:
            s.add(i*i)
            if (c - i*i) in s:
                return True
        else:
            break
    return False

if __name__ == "__main__":
    print(judgeSquareSum(5))
