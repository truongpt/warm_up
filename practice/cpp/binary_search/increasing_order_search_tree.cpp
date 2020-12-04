/*
- Problem: https://leetcode.com/problems/increasing-order-search-tree/
- Solution 1:
  - Inorder scan -> store all value to vector
  - Re-create BST from the vector value, with root is the smallest value.
- Solution 2:
  - Using stack to revert order of left size of original root.

*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {};
    TreeNode(int value, TreeNode* l, TreeNode* r) : val(value), left(l), right(r) {};    
};

void inorderScan(TreeNode* root, vector<int>& arr)
{
    if (root == nullptr) {
        return;    
    }

    inorderScan(root->left, arr);
    arr.push_back(root->val);
    inorderScan(root->right, arr);
}

TreeNode* increasingBST(TreeNode* root)
{
    vector<int> arr;
    inorderScan(root, arr);
    TreeNode* res = new TreeNode(0);
    TreeNode* t = res;
    for (auto it : arr) {
        t->right = new TreeNode(it);
        t = t->right;
    }
        
    return res->right;
}

TreeNode* increasingBST2(TreeNode* root)
{
    stack<TreeNode*> st = {};
    TreeNode *res = nullptr, *pre = nullptr;
    while (root || !st.empty()) {
        while (root) {
            st.push(root);
            root = root->right;
        }
        root = st.top();
        st.pop();

        if (pre == nullptr) {
            res = root;
            pre = root;
        } else {
            pre->right = root;
            pre = pre->right;
        }
        root->left = nullptr;
        root = root->right;
    }

    return res;
}

int main(void)
{

    
}
