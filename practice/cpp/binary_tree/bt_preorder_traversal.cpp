/*
- Problem: https://leetcode.com/explore/learn/card/data-structure-tree/134/traverse-a-tree/928/
- Solution:
  - preorder binary tree: root -> left subtree -> right subtree
  - Rercusion.
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {};
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {};
    TreeNode(int v, TreeNode* l, TreeNode* r): val(v), left(l), right(r) {};
};

void preorderTraversalRecur(TreeNode* root, vector<int>& arr)
{
    if (root == nullptr) {
        return;
    }

    arr.push_back(root->val);
    preorderTraversalRecur(root->left, arr);
    preorderTraversalRecur(root->right, arr);
}

vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> arr = {};
    preorderTraversalRecur(root, arr);
    return arr;
}

int main(void)
{

}
