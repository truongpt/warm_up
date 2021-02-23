'''
- Problem: https://leetcode.com/problems/add-two-numbers/
- Solution:
  - Iterative for 2 list node.
  - Using remain variable to store remain value when sum of 2 node over 10.
  - Time and space complexity.
    - TC: O(n)
    - SC: O(0) // Using one list to store result value, so don't need extend memory. 
'''
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def addTwoNumbers(l1: ListNode, l2: ListNode) -> ListNode:
    if not l1:
        return l2
    if not l2:
        return l1
    if not l1 and not l2:
        return None

    remain = 0
    res = l1
    while l1 and l2:
        temp_val = l1.val + l2.val + remain
        l1.val = temp_val % 10
        remain = temp_val // 10
        pre1 = l1
        l1 = l1.next
        l2 = l2.next

    if not l1:
        pre1.next = l2
        l1 = l2
        
    while l1:
        temp_val = l1.val + remain
        l1.val = temp_val % 10
        remain = temp_val // 10
        pre1 = l1
        l1 = l1.next
    
    if remain:
        pre1.next = ListNode(remain)


    return res
    
if __name__ == "__main__":
    l1 = ListNode(1)
    l1.next = ListNode(2)
    l2 = ListNode(3)
    l2.next = ListNode(4)
    sum_res = addTwoNumbers(l1, l2)
    while sum_res:
        print(sum_res.val)
        sum_res = sum_res.next

    
