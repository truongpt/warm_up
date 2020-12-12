/*
- Problem: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
- Solution
  - Calculate depth all substree.
  - Find the subroot with depth of left == depth of right

*/

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {};
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {};
    TreeNode(int v, TreeNode* l, TreeNode* r): val(0), left(l), right(r) {};
};

int depth(TreeNode* root, unordered_map<TreeNode*, int>& m)
{
    if (root == nullptr) {
        return 0;
    }
    m[root] = 1 + max(depth(root->left, m), depth(root->right, m));
    return m[root];
}

TreeNode* getSubRoot(TreeNode* root, unordered_map<TreeNode*, int> m)
{
    if (root == nullptr) {
        return root;
    }

    if (m[root->left] == m[root->right]) {
        return root;
    } else if (m[root->left] > m[root->right]) {
        return getSubRoot(root->left, m);
    }
    return getSubRoot(root->right, m);
}

TreeNode* subtreeWithAllDeepest(TreeNode* root)
{
    unordered_map<TreeNode*, int> m;
    depth(root, m);
    return getSubRoot(root, m);    
}

int main(void)
{

}
