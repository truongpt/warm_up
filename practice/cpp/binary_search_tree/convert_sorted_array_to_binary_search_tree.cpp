/*
- Problem: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree
*/

#include <iostream>
#include <vector>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(): val(0), left(nullptr), right(nullptr) {};
  TreeNode(int val): val(val), left(nullptr), right(nullptr) {};
};

TreeNode* sortedArrayToBST(std::vector<int>& nums, int start, int end) {
  if (start > end) {
    return nullptr;
  }
  int mid = start + (end - start) / 2;
  TreeNode* root = new TreeNode(nums[mid]);
  root->left = sortedArrayToBST(nums, start, mid-1);
  root->right = sortedArrayToBST(nums, mid+1, end);
  return root;
}

TreeNode* sortedArrayToBST(std::vector<int>& nums) {
  return sortedArrayToBST(nums, 0, nums.size()-1);
}

int main(void) {

}
