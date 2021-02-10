from queue import Queue

class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BinaryTree(object):
    def __init__(self, root):
        self.root = Node(root)
    def print_tree(self, traversal_type):
        if traversal_type == "preorder":
            return self.preorder_print(self.root, "")
        if traversal_type == "inorder":
            return self.inorder_print(self.root, "")
        if traversal_type == "postorder":
            return self.postorder_print(self.root, "")
        if traversal_type == "levelorder":
            return self.levelorder_print(self.root)
        else:
            print("Traversal type: " + str(traversal_type) + "is not supported")
            return false

    def preorder_print(self, start, tralversal):
        """
        root -> left -> right
        """
        if start:
            tralversal += (str(start.value) + "-")
            tralversal = self.preorder_print(start.left, tralversal)
            tralversal = self.preorder_print(start.right, tralversal)
        return tralversal
    def inorder_print(self, start, tralversal):
        # left -> root -> right
        if start:
            tralversal = self.inorder_print(start.left, tralversal)
            tralversal += (str(start.value) + "-")
            tralversal = self.inorder_print(start.right, tralversal)
        return tralversal
    def postorder_print(self, start, tralversal):
        # left -> right -> root
        if start:
            tralversal = self.postorder_print(start.left, tralversal)
            tralversal = self.postorder_print(start.right, tralversal)
            tralversal += (str(start.value) + "-")
        return tralversal
    def levelorder_print(self, start):
        if start is None:
            return
        q = Queue()
        q.enqueue(start)
        tralversal = ""
        while len(q) > 0:
            tralversal += str(q.peek()) + "-"
            node = q.dequeue()

            if node.left:
                q.enqueue(node.left)
            if node.right:
                q.enqueue(node.right)
        return tralversal

        
