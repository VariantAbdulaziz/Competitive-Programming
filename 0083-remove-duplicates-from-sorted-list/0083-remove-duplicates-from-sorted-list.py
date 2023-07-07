# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

"""
d - 1 - 3
    ^
        ^

"""
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:

        
        dummy = ListNode(-101)
        holder = dummy
        seeker = head
        while seeker:
            if seeker.val != holder.val:
                holder.next = seeker
                holder = seeker
            seeker = seeker.next
        holder.next = None
        return dummy.next
            
            
        