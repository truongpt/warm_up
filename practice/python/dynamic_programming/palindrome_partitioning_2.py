"""
- Problem: https://leetcode.com/problems/palindrome-partitioning-ii
"""

def minCut(s):
    N = len(s)
    dp = [[False] * N for i in range(N)]
    
    for i in range(N):
        dp[i][i] = True

    for i in range (1, N):
        for j in reversed(range(i)):               
            if s[i] == s[j] and (j == i-1 or dp[j+1][i-1] == True):
                dp[j][i] = True

    part_cut = [N]*N
    part_cut[0] = 0
    for i in range(1,N):
        for j in range(i+1):
            if dp[j][i] == True:
                if j == 0:
                    part_cut[i] = 0
                else:
                    part_cut[i] = min(part_cut[i], part_cut[j-1] + 1)
    return part_cut[N-1]


if __name__ == "__main__":
    s = "ababababababababababababcbabababababababababababa"
    print(minCut(s))
    
