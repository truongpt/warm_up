'''
- Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
- Solution:
  - Using 2 state BUY and SELL, and result is max value at SELL state 
  - Find max value for each state.
    - for BUY: comparing buy and NOT buy
    - for SELL: comparing sell and NOT sell with pre state must be buy
  - Time and space complexity
    - TC: O(n)
    - SC: O(1)
'''

def maxProfit(nums: list) -> int:
    sell = 0
    buy = -nums[0]
    for it in nums:
        buy = max(buy, -it)
        sell = max(sell, buy + it)
    return sell

if __name__ == "__main__":
    nums = [7,6,1,5,9]
    print(maxProfit(nums))


