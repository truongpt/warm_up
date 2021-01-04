/*
- Problem: https://leetcode.com/problems/merge-two-sorted-lists/
- Solution:
  - Check each element of each list, select each of them by compared result.
  - Implementing by recursive or iteractive

*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {};
    ListNode(int v): val(v), next(nullptr) {};
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if (l1 == nullptr) {
        return l2;
    }
    if (l2 == nullptr) {
        return l1;
    }

    if (l1->val <= l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }

    l2->next = mergeTwoLists(l1, l2->next);
    return l2;
}

ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) {
        return l2;
    }
    if (l2 == nullptr) {
        return l1;
    }
        
    ListNode* root;
        
    if (l1->val <= l2->val) {
        root = l1;
        l1 = l1->next;
    } else {
        root = l2;
        l2 = l2->next;
    }
        
    ListNode* pre = root;

    while (nullptr != l1 && nullptr != l2) {
        if (l1->val <= l2->val) {
            pre->next = l1;
            l1 = l1->next;
        } else {
            pre->next = l2;
            l2 = l2->next;
        }
        pre = pre->next;
            
    }
        
    pre->next = (l1 ? l1 : l2);
    return root;
}


int main(void)
{


}
