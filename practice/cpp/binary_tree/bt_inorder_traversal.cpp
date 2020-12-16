/*
- Problem: https://leetcode.com/problems/binary-tree-inorder-traversal
- Solution: 
  - inorder binary tree: left subtree -> root -> right subtree
  - Rercusion.
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val (0), left(nullptr), right(nullptr) {};
    TreeNode(int v): val (v), left(nullptr), right(nullptr) {};
    TreeNode(int v, TreeNode* l, TreeNode* r): val (0), left(l), right(r) {};
};

void traversalRecursion(TreeNode* root, vector<int>& arr)
{
    if (root == nullptr) {
        return;
    }

    traversalRecursion(root->left, arr);
    arr.push_back(root->val);
    traversalRecursion(root->right, arr);
}

vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> arr = {};
    traversalRecursion(root, arr);
    return arr;
}

int main(void)
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    vector<int> res = inorderTraversal(root);

    for (auto it : res) {
        cout << it << ",";
    }
    cout << endl;
}
