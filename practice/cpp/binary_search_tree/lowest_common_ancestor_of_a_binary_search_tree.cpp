/*
- Problem: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
*/

#include <iostream>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(): val(0), left(nullptr), right(nullptr) {};
  TreeNode(int val): val(val), left(nullptr), right(nullptr) {};
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  auto ancestor = root;
  while (ancestor) {
    if (p->val > ancestor->val && q->val > ancestor->val) {
      ancestor = ancestor->right;
    } else if (p->val < ancestor->val && q->val < ancestor->val) {
      ancestor = ancestor->left;
    } else {
      return ancestor;
    }
  }
  return nullptr;
}

int main(void) {
  TreeNode* root = new TreeNode(2);
  root->left = new TreeNode(1);
  root->right = new TreeNode(3);
  auto p = root->left, q = root->right;
  auto result = lowestCommonAncestor(root, p, q);
  std::cout << "Result: " << result->val << std::endl;
}
