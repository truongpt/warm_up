"""
- Problem: https://leetcode.com/problems/array-nesting
"""
def arrayNesting(nums):
    n = len(nums)
    max_len = 0
    s = set()
    for i in range(n):
        cur_len = 0
        index = i
        while index not in s:
            s.add(index)
            cur_len += 1
            index = nums[index]
        max_len = max(max_len, cur_len)

    return max_len

if __name__ == "__main__":
    nums = [5,4,6,3,2,1,0]
    print(arrayNesting(nums))
