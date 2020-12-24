/*
- Problem: https://leetcode.com/problems/swap-nodes-in-pairs/

- Solution 1:
  - Iteractive to swap each node pair
  - Time and space complexity.
    - TC: O(n)
    - SC: O(1)

- Solution 2:
  - Recursive
  - Time and space complexity.
    - TC: O(n)
    - SC: O(n)
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {};
    ListNode(int v): val(v), next(nullptr) {};
};


ListNode* swapPairs1(ListNode* head)
{
    if (nullptr == head || nullptr == head->next) {
        return head;
    }

    ListNode *cur, *pre = nullptr, *next;
    cur = head;
    head = head->next;
    /*1  2->3->4->5->6
         ^  ^  ^
         p  c  n
    */

    while (nullptr != cur && nullptr != cur->next) {
        next = cur->next;
        cur->next = next->next;
        next->next = cur;
        if (nullptr != pre) pre->next = next;
        pre = cur;
        cur = cur->next;
    }

    return head;
}

ListNode* swapPairs2(ListNode* head)
{
    if (nullptr == head || nullptr == head->next) {
        return head;
    }

    ListNode* second = head->next;
    head->next = swapPairs2(second->next);
    second->next = head;

    return second;
}

int main(void)
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    ListNode* cur = head;
    while (cur) {
        cout << cur->val << ",";
        cur = cur->next;
    }
    cout << endl;
    head = swapPairs1(head);

    while (head) {
        cout << head->val << ",";
        head = head->next;
    }
    cout << endl;

}
