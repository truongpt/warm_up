'''
- Problem: https://leetcode.com/problems/wiggle-subsequence
- Solution:
  - len[i] -> store max len wiggle subsequence from 0 -> i
  - d[i] -> store sign of nums[i] with previous element.
  - len[i] = max(len[i], len[j]+1) with j = i-1 -> 0 and condition (nums[i] - nums[j])*d[j] < 0
  - Time and space complexity.
    - TC: O(n^2)
    - SC: O(n)
'''

def wiggleMaxLength(nums: list) -> int:
    if len(nums) < 2:
        return len(nums)
    
    max_len = [1]*len(nums)
    d = [0]*len(nums)
    
    for i in range(1, len(nums)):
        for j in reversed(range(i)):
            if (nums[i] - nums[j])*d[j] < 0 or (j == 0 and nums[i] - nums[0] != 0):
                if max_len[i] < max_len[j]+1:
                    max_len[i] = max_len[j]+1
                    if nums[i] - nums[j] > 0:
                        d[i] = 1
                    else:
                        d[i] = -1

    return max_len[len(nums)-1]

if __name__ == "__main__":
    arr = [1,17,5,10,13,15,10,5,16,8]
    print(wiggleMaxLength(arr))
