'''
- Problem: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
- Solution:
  - Find start index of subarray.
    - Find the smallest point, which array is not ascending order.
    - Find min value after the point.
    - Base on the min value -> find start index of subarray.
  - Find end index of subarray.
    - Find the largest point, which array is not ascending order.
    - Find max value before the point.
    - Base on the max value -> find end index of subarray.
  - Time and space complexity.
    - TC: O(n)
    - SC: O(1)
'''
def findUnsortedSubarray(nums: list) -> int:
    start = len(nums)-1
    end = 0
    
    pivot = -1
    for i in range(len(nums)):
        if pivot == -1 and i < len(nums)-1 and nums[i] > nums[i+1]:
            pivot = i+1
        if pivot != -1 and nums[i] < nums[pivot]:
            pivot = i
            
    for i in reversed(range(pivot)):
        if nums[i] > nums[pivot]:
            start = i
    
    pivot = -1
    for i in reversed(range(len(nums))):
        if pivot == -1 and i > 0 and nums[i-1] > nums[i]:
            pivot = i-1
        if pivot != -1 and nums[i] > nums[pivot]:
            pivot = i
    
    for i in range(pivot, len(nums)):
        if nums[i] < nums[pivot]:
            end = i
    
    if end > start:
        return end - start + 1
    
    return 0

if __name__ == "__main__":
    arr = [5,2,3,4,5]
    print(findUnsortedSubarray(arr))
    
