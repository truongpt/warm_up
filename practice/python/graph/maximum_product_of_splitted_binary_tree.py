"""
- Problem: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree
"""
class TreeNode:
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right

def dfs(root):
    if root == None:
        return 0    
    root.val += dfs(root.left) + dfs(root.right)
    return root.val

def product(root, total_sum):
    if root == None:
        return 0
    cur = root.val * (total_sum - root.val)
    left = product(root.left, total_sum)
    right = product(root.right, total_sum)
    return max(cur, max(left, right))

def maxProduct(root):    
    dfs(root)
    max_val = product(root, root.val)
    return max_val % 1000000007

if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(1)
    print(maxProduct(root))
    
