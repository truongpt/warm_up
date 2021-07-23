/*
- Problem: https://leetcode.com/problems/binary-tree-pruning
*/

#include <iostream>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(): val(0), left(nullptr), right(nullptr) {};
  TreeNode(int val): val(val), left(nullptr), right(nullptr) {};
};

TreeNode* pruneTree(TreeNode* node) {
  if (!node) {
    return nullptr;
  }

  node->left = pruneTree(node->left);
  node->right = pruneTree(node->right);

  if (!node->left && !node->right && node->val == 0) {
    return nullptr;
  }
  return node;
}

int main(void) {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(0);
  TreeNode* result = pruneTree(root);

  if (root->left || root->right || root->val != 1) {
    std::cout << "Fail" << std::endl;
    return -1;
  }

  std::cout << "OK" << std::endl;
  return 0;

}
