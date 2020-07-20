// problem: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode* l, TreeNode* r) : val(0), left(l), right(r) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        return 0;
    }
};

int main(void)
{
    return 0;
}
