/*
- Problem: https://leetcode.com/problems/range-sum-of-bst/
  - Given the root node of a binary search tree, return the sum of values of all nodes with a value in the range [low, high].

- Clarify:
  - root value < low -> go right side
  - root value > high -> go left side
  - root value in range -> + root value -> go both side

*/

#include<iostream>

using namespace;

struct TreeNode* {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
    TreeNode(int value, TreeNode* l, TreeNode* r) : val(0), left(l), right(r) {}
};

int rangeSumBST(TreeNode* root, int low, int high)
{
    if (nullptr == root) {
        return 0;
    }

    if (low > root->val) {
        return rangeSumBST(root->right, low, high);
    } else if (high < root->val) {
        return rangeSumBST(root->left, low, high);
    }

    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}
