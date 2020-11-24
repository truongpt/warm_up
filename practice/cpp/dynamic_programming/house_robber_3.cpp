/*
- Problem: https://leetcode.com/problems/house-robber-iii/

```
Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1
```

- Solution 1
  - rob root = max (rob left + rob right, root value + rob left left + rob left right + rob right left + rob right right)
  - Top down by recursion + memoization

- Solution 2
  - Idea is same as solution 1 but difference implementation.

*/

#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {};
    TreeNode(int v, TreeNode* l, TreeNode* r) : val(0), left(l), right(r) {};
};


// Solution 1
unordered_map<TreeNode*, int> m;
int rob(TreeNode* root)
{
    if (nullptr == root) {
        return 0;
    }

    if (0 != m[root]) {
        return m[root];
    }

    int val1 = rob(root->left) + rob(root->right);
    int val2 = root->val + (nullptr != root->left ? (rob(root->left->left) + rob(root->left->right)) : 0)
        + (nullptr != root->right ? (rob(root->right->left) + rob(root->right->right)) : 0);

    m[root] = max(val1, val2);
    return m[root];
}

// Solution 2
int dfs(TreeNode* root, int& l, int& r)
{
    if (nullptr == root) {
        l = 0, r = 0;
        return 0;
    }

    int ll = 0, lr = 0, rl = 0, rr = 0;
    l = dfs(root->left, ll, lr);
    r = dfs(root->right, rl, rr);

    return max(root->val + ll + lr + rl + rr, l + r);
}

int rob2(TreeNode* root)
{
    int l = 0, r = 0;
    return dfs(root, l, r);
}

int main(void)
{
    TreeNode* root =  new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    cout << rob(root) << endl;

}
