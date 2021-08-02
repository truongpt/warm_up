'''
- Problem: https://leetcode.com/problems/two-sum/
'''

def twoSum(nums: list, target: int) -> list:
    map_to_index = {}

    for i in range(len(nums)):
        if map_to_index.get(target - nums[i]) != None:
            return [map_to_index[target - nums[i]], i]
        map_to_index[nums[i]] = i
    return [-1,-1]

if __name__ == "__main__":
    print(twoSum([3,2,4], 6))
