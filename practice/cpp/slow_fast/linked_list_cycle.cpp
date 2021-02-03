/*
- Problem: https://leetcode.com/problems/linked-list-cycle
- Solution:
  - Apply slow and fast pattern,
    - slow = slow->next
    - fast = fast->next->next
    - if fast == slow -> cycle linked list.
  - Time and space complexity
    - TC: O(n) 
    - SC: O(1)
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {};
};

bool hasCycle(ListNode* root)
{
    ListNode* slow = root;
    ListNode* fast = root;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main(void)
{
    ListNode* root = new ListNode();
    root->next = root;

    cout << hasCycle(root) << endl;

}
