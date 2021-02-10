from binary_tree import BinaryTree

tree = BinaryTree(1)
tree.root.left = BinaryTree(2)
tree.root.right = BinaryTree(3)

tree.root.left.left = BinaryTree(4)
tree.root.left.right = BinaryTree(5)
tree.root.right.left = BinaryTree(6)
tree.root.right.right = BinaryTree(7)

print(tree.print_tree("preorder"))
