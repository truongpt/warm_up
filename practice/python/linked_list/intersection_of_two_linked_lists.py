'''
- Problem: https://leetcode.com/problems/intersection-of-two-linked-lists
- Solution:
  - Adjust size of longer linked list to make 2 list is same size.
  - Check pair of each node.
  - Time and space complexity.
    - TC: O(n)
    - SC: O(1)
'''

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def getIntersectionNode(headA: ListNode, headB: ListNode) -> ListNode:
    cur_a = headA
    cur_b = headB
    len_a = 0
    len_b = 0
    while cur_a:
        len_a += 1
        cur_a = cur_a.next
    
    while cur_b:
        len_b += 1
        cur_b = cur_b.next
    
    cur_a = headA
    cur_b = headB
    
    if len_a > len_b:
        for i in range(len_a - len_b):
            cur_a = cur_a.next
    
    elif len_b > len_a:
        for i in range(len_b - len_a):
            cur_b = cur_b.next
    
    while cur_a:
        if cur_a == cur_b:
            return cur_a
        cur_a = cur_a.next
        cur_b = cur_b.next
    
    return None

if __name__ == "__main__":
    headA = ListNode(1)
    headB = ListNode(2)
    common = ListNode(3)
    headA.next = common
    headB.next = common
    res = getIntersectionNode(headA, headB)
    print (res.val)
