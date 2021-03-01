'''
- Problem: https://leetcode.com/problems/single-row-keyboard/
- Solution:
  - Using hashtable (dict) to maping character key -> position
  - Using prev to store previous position of character
    - res +=  abs(cur pos - prev pos).
  - Time and space complexity.
    - TC: O(n)
    - SC: O(n)
'''

def calculateTime(keyboard: str, word: str) -> int:
    pos = dict()
    for i in range(len(keyboard)):
        pos[keyboard[i]] = i

    res = 0
    prev = 0
    for it in word:
        res += abs(pos[it] - prev)
        prev = pos[it]

    return res

if __name__=="__main__":
    print(calculateTime("abcdefghijklmnopqrstuvwxyz", "conchoconcanconmeocon"))
