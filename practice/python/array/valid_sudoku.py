"""
- Problem: https://leetcode.com/problems/valid-sudoku
"""

def isValidSudoku(board):
    n = len(board)        
    for i in range(n):
        mr = set()
        ml = set()
        for j in range(n):
            row = board[i][j]
            if row != '.':
                if row in ml:
                    return False
                ml.add(row)
            
            col = board[j][i]
            if col != '.':
                if col in mr:
                    return False
                mr.add(col)
        
    for si in range(3):
        for sj in range(3):
            m = set()
            for i in range(si*3, si*3+3):
                for j in range(sj*3, sj*3+3):
                    c = board[i][j]
                    
                    if c != '.':
                        if c in m:
                            return False
                        m.add(c)
    return True


if __name__=="__main__":
    board = \
    [["8","3",".",".","7",".",".",".","."]
     ,["6",".",".","1","9","5",".",".","."]
     ,[".","9","8",".",".",".",".","6","."]
     ,["8",".",".",".","6",".",".",".","3"]
     ,["4",".",".","8",".","3",".",".","1"]
     ,["7",".",".",".","2",".",".",".","6"]
     ,[".","6",".",".",".",".","2","8","."]
     ,[".",".",".","4","1","9",".",".","5"]
     ,[".",".",".",".","8",".",".","7","9"]]

    print(isValidSudoku(board))
