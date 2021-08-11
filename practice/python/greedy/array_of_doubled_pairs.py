"""
- Problem: https://leetcode.com/problems/array-of-doubled-pairs
"""
import collections
from collections import Counter

def canReorderDoubled(arr):
    cnt = Counter(arr)
    arr.sort()
    for it in arr:
        if cnt[it] == 0: continue
        if it < 0 and it % 2 != 0: return False
        cand = it*2 if it > 0 else it // 2
        if cnt[cand] == 0: return False
        
        cnt[it] -= 1
        cnt[cand] -= 1
    return True    

if __name__ == "__main__":
    print(canReorderDoubled([-4,2,-2,4]))
