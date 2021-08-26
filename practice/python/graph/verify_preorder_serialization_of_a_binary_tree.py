"""
- Problem: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
"""
def isValidSerialization(preorder):
    p = preorder.split(',')
    n = len(p)
    need = 1
    for i in range(n):
        if p[i] == '#':
            need -= 1
        else:
            need += 1
        if need == 0 and i != n-1:
            return False
    return need == 0

if __name__ == "__main__":
    print(isValidSerialization("1,#,#"))
