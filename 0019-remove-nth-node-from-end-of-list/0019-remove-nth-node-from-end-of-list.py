# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        slow, fast = dummy, dummy

        # Move fast n steps ahead
        for i in range(n):
            fast = fast.next

        # Move both pointers together until fast reaches end
        while fast.next:
            slow = slow.next
            fast = fast.next

        # Remove the nth node from the end
        slow.next = slow.next.next

        return dummy.next