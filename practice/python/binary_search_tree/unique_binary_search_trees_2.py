"""
- Problem: https://leetcode.com/problems/unique-binary-search-trees-ii
"""
class TreeNode:
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right

def generateTreesSub(s, e):
    if s > e:
        return [None]
    res = []
    for i in range(s, e+1):
        left = generateTreesSub(s, i-1)
        right = generateTreesSub(i+1, e)
        
        for l in left:
            for r in right:
                root = TreeNode(i)
                root.left = l
                root.right = r
                res.append(root)
    return res

def generateTrees(n):
    return generateTreesSub(1,n)
        
if __name__ == "__main__":
    res = generateTrees(3)
