/*
- Problem:
- Intuition
```
preorder = [3,9,8,6,20,15,7]
            ^
inorder = [8,9,6,3,15,20,7]
                 ^
     3
   /  \
  9   20
 /\   / \
8 6  15 7

```

- Solution:

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {};
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {};
};


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    if (preorder.empty()) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(preorder[0]);

    vector<int> pre1 = {};
    vector<int> pre2 = {};
    vector<int> in1 = {};
    vector<int> in2 = {};

    int i = 0;
    for (; i < preorder.size(); i++) {
        if (preorder[i] != preorder[0]) {
            pre1.push_back(preorder[i]);
        }
        if (inorder[i] != preorder[0]) {
            in1.push_back(inorder[i]);
        } else {
            break;
        }
    }
    i++;
    for (; i < preorder.size(); i++) {
        pre2.push_back(preorder[i]);
        in2.push_back(inorder[i]);

    }

    root->left = buildTree(pre1, in1);
    root->right = buildTree(pre2, in2);

    return root;
}

int main(void)
{

}
