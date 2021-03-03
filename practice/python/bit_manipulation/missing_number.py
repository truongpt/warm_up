'''
- Problem: https://leetcode.com/problems/missing-number
- Solution:
  - Using xor bit: x ^ x = 0; x ^ 0 = x
  - Time and space complexity.
    - TC: O(n)
    - SC: O(1)
'''

def missingNumber(nums: list) -> int:
    res = len(nums)

    for i in range(len(nums)):
        res = res ^ i ^ nums[i]

    return res

if __name__ == "__main__":
    nums = [1,2,3,4,0]
    print(missingNumber(nums))

