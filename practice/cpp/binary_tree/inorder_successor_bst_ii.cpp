// problem: https://leetcode.com/explore/featured/card/september-leetcoding-challenge/556/week-3-september-15th-september-21st/3460/

// ANALYSIS
// if node is left leaf -> successor is parent.
// if node is right leaf -> find parent -> set parent -> right = NULL -> sucessor of parent?
// if node is not leaf -> if right leaf is NULL -> same as leaf.
// if node is not leaf and right leaf is not NULL -> find the most left leaf of right leaf.

#include <iostream>
using namespace std;

class Node {
  public:
    Node(int v) :
        val(v),
        left(nullptr),
        right(nullptr),
        parent(nullptr)
        {
        }
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        
        if (nullptr == node->right) {
            if (nullptr == node->parent) {
                return nullptr;
            } else if (node->parent->left == node) {
                return node->parent;
            } else {
                node->parent->right = nullptr;
                return inorderSuccessor(node->parent);
            }
        } else {
            Node* r = node->right;
            while (nullptr != r->left) {
                r = r->left;
            }
            return r;
        }
        return nullptr;
    }
};

int main(void)
{
    Node* root = new Node(2);
    root->left = new Node(1);
    root->left->parent = root;
    root->right = new Node(3);
    root->right->parent = root;

    Solution sol;
    {
        Node* r = sol.inorderSuccessor(root);
        cout << r->val << endl;
    }
    {
        Node* r = sol.inorderSuccessor(root->left);
        cout << r->val << endl;
    }
    {
        Node* r = sol.inorderSuccessor(root->right);
        if (nullptr != r) cout << r->val << endl;
    }
}
