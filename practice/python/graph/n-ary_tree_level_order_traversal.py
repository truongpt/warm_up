"""
- Problem: https://leetcode.com/problems/n-ary-tree-level-order-traversal
"""

class Node:
    def __init__(self, val = None, children = []):
        self.val = val
        self.children = children

def levelOrder(root: Node) -> list:
        if root == None:
            return []
        que = []
        que.append(root)
        res = []
        while len(que) != 0:
            n = len(que)
            level = []
            for i in range(n):
                cur = que[0]
                que.pop(0)
                level.append(cur.val)
                for child in cur.children:
                    que.append(child)
            res.append(level)
        return res    

if __name__ == "__main__":
    root = Node(1)
    root.children = [Node(2), Node(3)]
    res = levelOrder(root)
    print(res)
