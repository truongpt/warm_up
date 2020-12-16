/*
- Problem: https://leetcode.com/problems/binary-tree-postorder-traversal
- Solution: 
  - inorder binary tree: left subtree -> right subtree -> root
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
    traversalRecursion(root->right, arr);
    arr.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root)
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
    vector<int> res = postorderTraversal(root);

    for (auto it : res) {
        cout << it << ",";
    }
    cout << endl;
}
