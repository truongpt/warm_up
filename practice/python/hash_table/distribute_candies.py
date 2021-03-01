'''
- Problem: https://leetcode.com/problems/distribute-candies/
- Solution:
  - Using set to find number distinguishing number of candies.
  - Result is max (N/2, number distinguishing number of candies)
  - Time and space complexity.
    - TC: O(n)
    - SC: O(n)
'''

def distributeCandies(candyType : list) -> int:
    eat = set()
    N = len(candyType)//2

    for it in candyType:
        eat.add(it)
        if (len(eat) >= N):
            return N
    return eat

if __name__ == "__main__":
    candyType = [1,1,2,2,3,3]
    print(distributeCandies(candyType))
