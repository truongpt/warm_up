'''
- Problem: https://leetcode.com/problems/swap-nodes-in-pairs
- Solution:
  - Time and space complexity.
    - TC: O(n)
    - SC: O(1)
'''

class ListNode:
    def __init__(self, val = 0, next= None):
        self.val = val
        self.next = next

def swapPairs(head: ListNode) -> ListNode:
    if not head or not head.next:
        return head
    
    p = ListNode()
    pre_node = ListNode()
    p.next = head
    pre_node = p
    
    while pre_node.next and pre_node.next.next:
        cur_node = pre_node.next
        next_node = pre_node.next.next
        cur_node.next = next_node.next
        next_node.next = cur_node
        pre_node.next = next_node
        pre_node = cur_node
    
    return p.next

if __name__ == "__main__":
    l = ListNode(1)
    l.next = ListNode(2)
    l.next.next = ListNode(3)
    l.next.next.next = ListNode(4)

    tmp = l
    while tmp:
        print(tmp.val)
        tmp = tmp.next

    l = swapPairs(l)

    while l:
        print(l.val)
        l = l.next

