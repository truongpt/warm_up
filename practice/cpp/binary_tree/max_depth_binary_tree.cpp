/*
- Problem: https://leetcode.com/explore/featured/card/december-leetcoding-challenge/569/week-1-december-1st-december-7th/3551/
- Solution.
  - DFS

*/


#include <iostream>
#include <algorithm>

using namespace std;

structure TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left (nullptr), right(nullptr) {}
    TreeNode(int value) : val(value), left (nullptr), right(nullptr) {}
    TreeNode(int value, TreeNode* l, TreeNode* r) : val(value), left (l), right(r) {}
};

int maxDepth(TreeNode* root)
{
    if (nullptr == root) {
        return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main(void)
{

}
