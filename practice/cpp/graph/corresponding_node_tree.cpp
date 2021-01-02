/*
- Problem: https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree
- Solution:
  - Straightforward with DFS to find target and original tree -> return correspoding at cloned tree
  at the same time
  - Time & space complexity
    - TC: O(n)
    - SC: O(n)
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
    
TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    if (nullptr == original || nullptr == target) {
        return nullptr;
    }
        
    if (original == target) {
        return cloned;
    }
    TreeNode* left = getTargetCopy(original->left, cloned->left, target);
    if (nullptr != left) {
        return left;
    }
    TreeNode* right = getTargetCopy(original->right, cloned->right, target);
    return right;
}

int main(void)
{

}
