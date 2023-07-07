class Node:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class MyLinkedList:

    def __init__(self):
        self.dummy = Node()
        self.tail = self.dummy
        self.len = 0

    def get(self, index: int) -> int:
        
        if index >= self.len:
            return -1
        
        temp = self.dummy.next
        i = 0
        while i < index:
            temp = temp.next
            i += 1
            
        return temp.val
        

    def addAtHead(self, val: int) -> None:
        self.addAtIndex(0, val)
        
        

    def addAtTail(self, val: int) -> None:
        self.addAtIndex(self.len, val)

    def addAtIndex(self, index: int, val: int) -> None:
        if index < 0 or index > self.len:
            return
        i = 0
        temp = self.dummy
        while i < index:
            i += 1
            temp = temp.next

        temp.next = Node(val, temp.next)
        self.len += 1
        

    def deleteAtIndex(self, index: int) -> None:
        
        if index < 0 or index >= self.len:
            return
        i = 0
        temp = self.dummy
        while i < index:
            i += 1
            temp = temp.next
        temp.next = temp.next.next
        self.len -= 1
        


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)