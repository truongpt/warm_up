'''
- Problem: https://leetcode.com/problems/set-mismatch/
- Solution 1: Using set to check duplicate and missing.
  - Time and space complexity.
    - TC: O(n)
    - SC: O(n)
- Solution 2:
  - Using trick, change value nums to minus by scan value of nums -> set nums[ value - 1] *= -1
  - During scan, if nums[value - 1] is already minus -> this is duplicate value.
  - After reverse sign of nums, scan all to find nums[value -1] > 0 -> missing value.
  - Time and space complexity.
    - TC: O(n)
    - SC: O(1)
'''

def findErrorNums (nums: list) -> list:
    dup = -1
    missing = -1
    s = set()

    for it in nums:
        if it in s:
            dup = it
        else :
            s.add(it)

    for i in range(1, len(nums)+1):
        if not i in s:
            missing = i

    return [dup, missing]


    
def findErrorNums2 (nums: list) -> list:
    dup = -1
    missing = -1

    for it in nums:
        if nums[abs(it) - 1] < 0:
            dup = abs(it)
        else:
            nums[abs(it) - 1] *= -1

    for i in range(len(nums)):
        if nums[i] > 0:
            missing = i+1

    return [dup, missing]

if __name__ == "__main__":
    print(findErrorNums([1,1,2,3,4,5]))
    
