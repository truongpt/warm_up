"""
- Problem: https://leetcode.com/problems/count-good-nodes-in-binary-tree
"""

class TreeNode:
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right

def dfs(root, max_node):
    if root == None:
        return 0
    cnt = 0
    temp = max_node
    if max_node == None or root.val >= max_node.val:
        cnt += 1
        temp = root
    cnt += dfs(root.left, temp) + dfs(root.right, temp)
    return cnt

def goodNode(root):    
    return dfs(root, None)

if __name__ == "__main__":
    root = TreeNode(3)
    root.left = TreeNode(2)
    root.right = TreeNode(4)
    
    print(goodNode(root))
