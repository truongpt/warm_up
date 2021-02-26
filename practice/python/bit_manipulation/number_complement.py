'''
- Problem: https://leetcode.com/problems/number-complement
- Solution:
  - Using bitwise operator: AND and XOR -> return mask & (num ^ 0xFFFFFFFF)
  - mask is used to guaranteed bit change in range of num 
  - Time and space complexity.
    - TC: O(n)
    - SC: O(1)
'''
def findComplement(num: int) -> int:
    count = 0
    tmp = num
    mask = 0
    while tmp > 0:
        tmp = tmp >> 1
        mask |= 1 << count
        count += 1
    return mask & (num ^ 0xFFFFFFFF)

if __name__ == "__main__":
    print(findComplement(5))
