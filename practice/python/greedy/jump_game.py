'''
- Problem: https://leetcode.com/problems/jump-game
- Solution:
  - Greedy check reverse from last item. pos = last item position
  - Can go to pos if : pos - i <= nums[i]
  - Reduce pos = i
  - Final check condition if pos == 0
  - Time and space complexity.
    - TC: O(n)
    - SC: O(1)
'''
def canJump(nums : list) -> bool:
    pos = len(nums) - 1
    for i in reversed(range(len(nums))):
        if pos - i <= nums[i]:
            pos = i
    return pos == 0

if __name__ == "__main__":
    nums = [2,3,1,1,4]
    print(canJump(nums))
