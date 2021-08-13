"""
- Problem: https://leetcode.com/problems/set-matrix-zeroes
"""
def setZeroes(matrix):
    row_zero = 1
    row_len = len(matrix)
    col_len = len(matrix[0])
    
    for r in range(row_len):
        for c in range(col_len):
            if matrix[r][c] == 0:
                matrix[0][c] = 0
                if r == 0:
                    row_zero = 0
                else:
                    matrix[r][0] = 0
    for r in range(1, row_len):
        if matrix[r][0] == 0:
            for c in range(col_len):
                matrix[r][c] = 0
    
    for c in range(1, col_len):
        if matrix[0][c] == 0:
            for r in range(row_len):
                matrix[r][c] = 0
    
    if matrix[0][0] == 0:
        for r in range(row_len):
            matrix[r][0] = 0

    if row_zero == 0:
        for c in range(col_len):
            matrix[0][c] = 0

if __name__ == "__main__":
    matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
    print("Before: ", matrix)
    setZeroes(matrix)
    print("After: ", matrix)
    
