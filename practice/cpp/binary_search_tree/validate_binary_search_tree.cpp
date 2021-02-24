/*
- Problem:
- Solution:
  - Straight forward followting to spec of binary tree.
    - All number of left smaller than root.
    - All number of right larger than root.
  - Use recursion to maintain condition.
  - Time & space complexity.
    - TC: O(n)
    - SC: average O(log n), the worst case O(n)

*/

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {};
};

bool isValidBST(TreeNode* root, TreeNode* lesser = nullptr, TreeNode* greater = nullptr) {
    if (nullptr == root) {
        return true;
    }
    if (lesser && root->val <= lesser->val) {
        return false;
    }
        
    if (greater && root->val >= greater->val) {
        return false;
    }
        
    return isValidBST(root->left, lesser, root) && isValidBST(root->right, root, greater);
}


int main(void)
{


}
