'''
- Problem: https://leetcode.com/problems/reverse-string
- Solution:
  - swap s[i] & s[len - i - 1] with i = 0 ~ len/2
  - Time and space complexity.
    - TC: O(n)
    - SC: O(1)
'''
def reverseString(s: list) -> None:
    for i in range(len(s)//2):
        s[i], s[len(s) - i - 1] = s[len(s) - i - 1], s[i]

if __name__ == "__main__":
    s = ["h","e","l","l", "o"]
    print("before: ",s)
    reverseString(s)
    print("after: ",s)
    
