#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {
    }
};

class Solution {
public:
    vector<int> getAllElem(TreeNode* node1, TreeNode* node2) {
        vector<int> a1, a2;
        getTree(node1,a1);
        getTree(node2,a2);

        int i = 0, j = 0;
        vector<int> res;
        while (i < a1.size() && j < a2.size()) {
            if (a1[i] < a2[j]) {
                res.push_back(a1[i]);
                i++;
            } else if (a1[i] > a2[j]){
                res.push_back(a2[j]);
                j++;
            } else {
                res.push_back(a1[i]);
                res.push_back(a2[j]);
                i++,j++;
            }
        }
    
        if (i < a1.size()) {
            res.insert(res.end(), a1.begin()+i, a1.end());
        }
        if (j < a2.size()) {
            res.insert(res.end(), a2.begin()+j, a2.end());
        }
        return res;
    }
  
    void getTree(TreeNode* node, vector<int>& a) {
        if (nullptr == node) {return;}
        getTree(node->left, a);
        a.push_back(node->val);
        getTree(node->right, a);
    }
};

int main(void)
{
    Solution sol;
    TreeNode* node1 = new TreeNode(2);
    node1->left = new TreeNode(1);
    TreeNode* node2 = new TreeNode(3);
    node2->right = new TreeNode(4);
    vector<int> res = sol.getAllElem(node1, node2);
    for (auto it : res) {
        cout << it << ",";
    } 
    cout << endl;
}
