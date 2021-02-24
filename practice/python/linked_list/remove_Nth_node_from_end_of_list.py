'''
- Problem: https://leetcode.com/problems/remove-nth-node-from-end-of-list
- Solution:
  - one pass loop by using cnt variable to separate distance 2 pointers
  - Time and space complexity.
    - TC: O(n)
    - SC: O(1)
'''

class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

def removeNthFromEnd(head: ListNode, n: int) -> ListNode:
    pre_delete_node = ListNode()
    pre_delete_node.next = head
    it = head
    cnt = 0
    while it:
        if cnt < n:
            cnt += 1
        else:
            pre_delete_node = pre_delete_node.next
        it = it.next

    if pre_delete_node.next == head:
        head = head.next
    else:
        pre_delete_node.next = pre_delete_node.next.next

    return head

if __name__ == "__main__":
    l = ListNode(1)
    l.next = ListNode(2)
    removeNthFromEnd(l, 1)
    while l:
        print(l.val)
        l = l.next
