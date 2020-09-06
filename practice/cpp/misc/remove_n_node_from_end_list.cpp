#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {};
};

class Solution {
public:
    ListNode* removeNthNodeLast(ListNode* head, int n) {
        ListNode* t = head;
        int num = 0;
        while (nullptr != t) {
            num++;
            t = t->next; 
        }

        t = head;
        ListNode* pre = nullptr;
        int p = 0;
        while (p < num - n) {
            p++;
            pre = t;
            t = t->next;
        }
        if (nullptr == pre) return head->next;
        pre->next = t->next;
        return head;
    }
};

int main(void)
{
    Solution sol;
    ListNode* val = new ListNode(1);
    val->next = new ListNode(2);
    val->next->next = new ListNode(3);
    val->next->next->next = new ListNode(4);
    ListNode* res = sol.removeNthNodeLast(val,2);
    while (res != nullptr) {
        cout << res->val << ",";
        res = res->next;
    }
    cout << endl;
}
