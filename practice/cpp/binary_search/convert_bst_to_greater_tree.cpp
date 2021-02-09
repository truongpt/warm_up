/*
  - Problem: https://leetcode.com/problems/convert-bst-to-greater-tree
  - Solution:
  - DFS with consider order of binary search tree.
  - Time and space complexity.
  - TC: O(n)
  - SC: the worst case O(n), average case O(log n)
*/


#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {};
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {};
};

int dfs(TreeNode* root, TreeNode* larger) {
    if (root == nullptr) {
        if (larger == nullptr) {
            return 0;
        } else {
            return larger->val;
        }
    }
        
    root->val += dfs(root->right, larger);
        
    return dfs(root->left, root);
}
    
TreeNode* convertBST(TreeNode* root) {
    dfs(root, nullptr);
    return root;
}

int main(void)
{
    TreeNode* root = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left = new TreeNode(1);
    TreeNode* res = convertBST(root);
}
