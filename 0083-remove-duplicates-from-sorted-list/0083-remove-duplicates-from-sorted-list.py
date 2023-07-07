# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:

        
        dummy = ListNode(-101)
        tail = dummy
        run = head
        while run:
            if run.val != tail.val:
                tail.next = run
                tail = run
            run = run.next
        tail.next = None
        return dummy.next
            
            
        