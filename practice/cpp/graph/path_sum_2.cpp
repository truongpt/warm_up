/*
- Problem: https://leetcode.com/problems/path-sum-ii
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

void findPath(TreeNode* root, std::vector<std::vector<int>>& total_path, std::vector<int> cur_path, int cur_target) {
  if (!root) {
    return;
  }
  cur_target -= root->val;
  cur_path.push_back(root->val);

  if (0 == cur_target && !root->left && !root->right) {
    total_path.push_back(cur_path);
    return;
  }
  findPath(root->left, total_path, cur_path, cur_target);
  findPath(root->right, total_path, cur_path, cur_target);
}

std::vector<std::vector<int>> pathSum(TreeNode* root, int target_sum) {
  std::vector<std::vector<int>> total_path{};
  std::vector<int> cur_path{};

  findPath(root, total_path, cur_path, target_sum);
  return total_path;
}

int main(void) {

}
