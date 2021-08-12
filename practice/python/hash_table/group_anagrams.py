"""
- Problem: https://leetcode.com/problems/group-anagrams
"""

def groupAnagrams(strs):
    m = {}
    for s in strs:
        key = ''.join(sorted(s))
        m[key] = m.get(key, []) + [s]

    return list(m.values())

if __name__ == "__main__":
    print(groupAnagrams(["eat","tea","tan","ate","nat","bat"]))
