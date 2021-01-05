/*
- Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
- Solution: ...
```
Input: head = [1,    2,   3,3,4,4,5]
               ^     ^    ^
              pre    cur
```
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {};
    ListNode(int v): val(v), next(nullptr) {};
};

ListNode* deleteDuplicate(ListNode* head)
{
    ListNode* root = new ListNode(0);
    ListNode* pre = root;
    ListNode* cur = head;

    while (cur) {
        if (nullptr == cur->next || cur->val != cur->next->val) {
            pre->next = cur;
            cur = cur->next;
            pre = pre->next;
        } else {
            int temp = cur->val;
            while (cur && cur->val == temp) {
                cur = cur->next;
            }
        }
    }

    pre->next = cur;

    return root->next;
}

int main(void)
{

}
