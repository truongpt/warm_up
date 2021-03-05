'''
- Problem: https://leetcode.com/problems/validate-binary-search-tree
- Solution:
  - Confirm condition BST for all node of the tree.
  - Implementation: Recursive, Iterative ... 
  - Time and space complexity.
    - TC: O(n)
    - SC: O(n)
'''
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


# recrusive
def _isValidBST(root: TreeNode, smaller: TreeNode, bigger: TreeNode) -> bool:
    if not root:
        return True
    if (smaller and smaller.val >= root.val) or \
       (bigger and bigger.val <= root.val):
        return False
    return _isValidBST(root.left, smaller, root) and _isValidBST(root.right, root, bigger)
        
def isValidBST(root: TreeNode) -> bool:
    return _isValidBST(root, None, None)
    

# iteractive by stack
def isValidBST1(root: TreeNode) -> bool:
    if not root:
        return True
    stack = [(root, None, None)]
    while stack:
        root , lower, upper = stack.pop()
        if not root:
            continue
        if (lower and lower.val >= root.val) or \
           (upper and upper.val <= root.val):
            return False
        stack.append((root.left, lower, root))
        stack.append((root.right, root, upper))
    return True

# using inorder scan
def isValidBST2(root: TreeNode) -> bool:
    stack, prev = [], None
    
    while stack or root:
        while root:
            stack.append(root)
            root = root.left
        
        root = stack.pop()
        
        if prev and prev.val >= root.val:
            return False
        prev = root
        root = root.right
    
    return True
    
if __name__ == "__main__":
    root = TreeNode(2)
    root.left = TreeNode(1)
    root.right = TreeNode(3)

    print (isValidBST(root))
    print (isValidBST1(root))
    print (isValidBST2(root))

