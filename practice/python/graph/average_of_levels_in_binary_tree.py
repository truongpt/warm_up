'''
- Problem: https://leetcode.com/problems/average-of-levels-in-binary-tree/
- Solution:
  - Using bfs scan each level and calculate average.
  - Time and space complexity.
    - TC: O(n)
    - SC: O(n)
'''

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def averageOfLevels(root: TreeNode) -> list:
    
    if not root:
        return []
    
    q = []
    res = []
    
    q.append(root)
    
    while q:
        level_num = len(q)
        average = 0.0
        
        for i in range(level_num):
            cur = q.pop(0)
            average += float(cur.val)
            
            if cur.left:
                q.append(cur.left)

            if cur.right:
                q.append(cur.right)
        
        res.append(average/level_num)
    
    return res

if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    res = averageOfLevels(root)

    print (res)
