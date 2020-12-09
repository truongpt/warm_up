/*
- problem: https://www.interviewcake.com/question/c/balanced-binary-tree
- solution:
  - check diff max height - min height of all nodes. 

*/

#include <iostream>
#include <queue>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {};
    TreeNode(int v, TreeNode* l, TreeNode* r) : val(0), left(l), right(r) {};
};

bool isBalanced(TreeNode* root)
{
    int level = 0;
    int min_l = INT_MAX, max_l = INT_MIN;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        level++;
        for (int i = 0; i < n; i++) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur == nullptr) {
                continue;
            }

            if (cur->left == nullptr && cur->right == nullptr) {
                min_l = min(min_l, level);
                max_l = max(max_l, level);
                continue;
            }

            q.push(cur->left);
            q.push(cur->right);            
        }
    }

    return (max_l - min_l <= 1);

}

int main(void)
{
// add test code

}
