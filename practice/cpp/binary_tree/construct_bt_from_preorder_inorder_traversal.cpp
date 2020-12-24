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

}

int main(void)
{

}
