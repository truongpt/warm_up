/*
- Problem: https://leetcode.com/problems/symmetric-tree/
- Solution:
  - Straight forward confirm with condition symmetric tree.
  - S1: BSF by 2 queue.
  - S2: DFS by recursion.
*/

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {};
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {};
};

bool isSymmetricTreeBFS(TreeNode* root)
{
    if (!root || (!root->left && !root->right)) {
        return true;
    }

    queue<TreeNode*> lq, rq;
    lq.push(root->left);
    rq.push(root->right);
    while (!lq.empty() && !rq.empty()) {
        if (lq.size() != rq.size()){
            return false;
        }

        TreeNode* lnode = lq.front();
        lq.pop();
        TreeNode* rnode = rq.front();
        rq.pop();

        if (!lnode && !rnode) {
            continue;
        }

        if ((nullptr == lnode) ^ (nullptr == rnode)) {
            return false;
        } else if (lnode->val != rnode->val) {
            return false;
        }
        lq.push(lnode->left);
        lq.push(lnode->right);
        rq.push(rnode->right);
        rq.push(rnode->left);
    }

    return lq.empty() && rq.empty();
}


bool dfs(TreeNode* l, TreeNode* r)
{
    if (!l && !r) {
        return true;
    }

    if ((nullptr == l) ^ (nullptr == r)) {
        return false;
    }

    if (l->val != r->val) {
        return false;
    }

    return dfs(l->left, r->right) && dfs(l->right, r->left);
}

bool isSymmetricTreeDFS(TreeNode* root)
{
    if (nullptr == root) {
        return true;
    }
    return dfs(root->left, root->right);
}

int main(void)
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    cout << isSymmetricTreeBFS(root) << endl;
    cout << isSymmetricTreeDFS(root) << endl;

    return 0;
}
