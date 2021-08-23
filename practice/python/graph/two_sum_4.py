"""
- Problem: https://leetcode.com/problems/two-sum-iv-input-is-a-bst
"""

class TreeNode:
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.right = right
        self.left = left

def dfs(root, s, k):
    if root is None:
        return False
    if root.val in s:
        return True
    s.add(k - root.val)
    
    return dfs(root.left, s, k) or dfs(root.right, s, k)
    

def findTarget(root, k):
    s = set()
    return dfs(root, s, k)


if __name__ == "__main__":
    root = TreeNode(2)
    root.left = TreeNode(3)
    root.right = TreeNode(4)
    print(findTarget(root, 6))
    print(findTarget(root, 5))
    print(findTarget(root, 4))
