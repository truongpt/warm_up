"""
- Problem: https://leetcode.com/problems/minimum-window-substring
"""

def minWindow(s, t):
    def checkSub(dict_t, dict_s):
        for key in dict_t:
            if key not in dict_s.keys() or dict_t[key] > dict_s[key]:
                return False
        return True
    
    dict_t = {k: 0 for k in t}
    dict_s = {k: 0 for k in s}
    
    len_t = len(t)
    len_s = len(s)
    if len_t > len_s:
        return ""
    
    for c  in t:
        dict_t[c] += 1
    
    count = len_s + 1
    pivot = 0
    l = 0
    r = 0
    
    while r < len_s:
        dict_s[s[r]] += 1
        while True == checkSub(dict_t, dict_s):
            if r - l + 1 < count:
                pivot = l
                count = r - l + 1
            dict_s[s[l]] -= 1
            l += 1
        r += 1
        
        
    return "" if count == len_s + 1 else s[pivot : pivot + count]
        

if __name__ == "__main__":
    print(minWindow("ADOBECODEBANC","ABC"))
