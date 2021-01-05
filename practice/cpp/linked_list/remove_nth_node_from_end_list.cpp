/*
- Problem: https://leetcode.com/problems/remove-nth-node-from-end-of-list
- Solution: Using next n node from end pointer to implement by one pass.
  - Time and space complexity:
    - TC: O(n)
    - SC: O(1)

```
[1,2,3,4,5], n = 2
     ^
    cur

[1,2,3,4,5], n = 1
       ^
      cur
```
*/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {};
    ListNode(int v): val(v), next(nullptr) {};
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* cur = nullptr;
    ListNode* next_n = head;

    int i = 0;
    while (next_n) {

        next_n = next_n->next;

        if (i == n) {
            cur = head;
        } else if (i > n) {
            cur = cur->next;
        }
            
        i++;
    }

    if (nullptr == cur) {
        return head->next;
    }

    cur->next = cur->next->next;
    return head;
   
}

int main(void)
{


}

