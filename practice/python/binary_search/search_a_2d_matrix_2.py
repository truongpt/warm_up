'''
- Problem: https://leetcode.com/problems/search-a-2d-matrix-ii/
- Solution:
  - Using binary search for row 0 -> find the largest index with matrix[0][r] < target.
  - Using binary search for colum r -> find the smallest index with matrix[t][r] > target.
  - Find from position (r,t)
  - Time and complexity.
    - TC: O(log n + log m + m + n)
    - SC: O(1)

'''
def searchMatrix(matrix: list, target: int) -> bool:
    if not matrix or not matrix[0]:
        return False
    R = len(matrix)
    C = len(matrix[0])
    l = 0
    r = C-1
    # binary search to find r
    while l <= r:
        m = l +(r-l)//2
        if matrix[0][m] == target:
            return True
        elif matrix[0][m] < target:
            l = m + 1
        else:
            r = m - 1
    
    if r < 0 or r >= C:
        return False
    
    t = 0
    b = R-1

    # binary search to find t
    while t <= b:
        m = t + (b-t)//2
        if matrix[m][r] == target:
            return True
        elif matrix[m][r] < target:
            t = m+1
        else:
            b = m-1

    # base on pos (t,r) -> search
    while r >= 0 and r < C and t >= 0 and t < R:
        if matrix[t][r] == target:
            return True
        elif matrix[t][r] < target:
            t += 1
        else:
            r -= 1
    
    return False

if __name__ == "__main__":
    matrix = [[1,4,7,11,15],
              [2,5,8,12,19],
              [3,6,9,16,22],
              [10,13,14,17,24],
              [18,21,23,26,30]]

    print (searchMatrix(matrix, 5))
    
