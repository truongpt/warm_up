"""
- Problem: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
"""
def findMin(nums):
    l = 0
    r = len(nums)
    while l <= r:
        m  = l + (r-l)//2
        if nums[m] > nums[-1]:
            l = m+1
        else:
            r = m-1
    return nums[l]

if __name__ == "__main__":
    nums = [1,2,3,4,5,0]
    print(findMin(nums))
