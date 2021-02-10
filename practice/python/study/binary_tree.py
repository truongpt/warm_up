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
        elif traversal_type == "inorder":
            print("1")
            #return self.inorder_print(tree.root, "")
        elif traversal_type == "postorder":
            print("2")
            #return self.postorder_print(tree.root, "")
        else:
            print("Traversal type: " + str(traversal_type) + "is not supported")
            return false
    def preorder_print(self, start, tralversal):
        """
        root -> left -> right
        """
        if start:
            tralversal += (str(start.value) + "-")
            tralversal = preorder_print(start.left, tralversal)
            tralversal = preorder_print(start.right, tralversal)
        return tralversal
        

        
