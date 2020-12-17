/*
- Problem: https://leetcode.com/problems/binary-tree-preorder-traversal/
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

void traversalRecursion(TreeNode* root, vector<int>& arr)
{
    if (root == nullptr) {
        return;
    }

    arr.push_back(root->val);
    traversalRecursion(root->left, arr);
    traversalRecursion(root->right, arr);
}

vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> arr = {};
    traversalRecursion(root, arr);
    return arr;
}

vector<int> preorderTraversalMorris(TreeNode* root)
{
    vector<int> arr = {};
    TreeNode* node = root;
    while (node) {
        if (nullptr == node->left) {
            arr.push_back(node->val);
            node = node->right;
        } else {
            TreeNode* cur = node->left;
            while (cur->right != nullptr && cur->right != node) {
                cur = cur->right;
            }

            if (cur->right == nullptr) {
                arr.push_back(node->val);
                cur->right = node;
                node = node->left;
            } else {
                cur->right = nullptr;
                node = node->right;
            }

        }

    }

    return arr;
}

int main(void)
{
  
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    {
        vector<int> res = preorderTraversal(root);

        for (auto it : res) {
            cout << it << ",";
        }
        cout << endl;
    }

    {
        vector<int> res = preorderTraversalMorris(root);
        for (auto it : res) {
            cout << it << ",";
        }
        cout << endl;
    }
}
