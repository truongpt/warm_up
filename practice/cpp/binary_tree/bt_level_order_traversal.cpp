/*
- Problem:
- Solution:
  - Straight forward by BFS.
  - Time and space complexity.
    - TC: O(n)
    - SC: O(n)
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {};
};

vector<vector<int>> levelOrder(TreeNode* root)
{
    if (nullptr == root) return {};
    queue<TreeNode*> q;

    q.push(root);
    vector<vector<int>> res = {};
    vector<int> elem = {};

    while (!q.empty()) {
        int n = q.size();
        elem.clear();
        for (int i = 0; i < n; i++) {
            TreeNode* cur = q.front();
            q.pop();
            elem.push_back(cur->val);
            if (cur->left)  q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        res.push_back(elem);
    }

    return res;
}

int main(void)
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    vector<vector<int>> res = levelOrder(root);
    for (auto v : res) {
        for (auto e : v) {
            cout << e << ",";
        }
        cout << endl;
    }

}
