"""
- Problem: https://leetcode.com/problems/flip-string-to-monotone-increasing/
"""
def minFlipsMonoIncr(s):
    n = len(s)
    f0 = [0]*(n+1)
    f1 = [0]*(n+1)
    for i in range(1, n+1):
        f0[i] = f0[i-1] + (0 if s[i-1] == '0' else 1)
    
    for j in reversed(range(n)):
        f1[j] = f1[j+1] + (1 if s[j] == '0' else 0)
    
    res = f0[0] + f1[0]
    
    for i in range(n+1):
        res = min(res, f0[i] + f1[i])
    return res

if __name__ == "__main__":
    s = "010110"
    print(minFlipsMonoIncr(s))
