import heapq

class Book:
    def __init__(self, a):
        self._min = 1
        self._max = len(a)

    def empty(self):
        return self.min() >= self.max()

    def min(self):
        return self._min

    def max(self):
        return self._max

    def evictMin(self):
        if not self.empty():
            self._min += 1

    def evictMax(self):
        if not self.empty():
            self._max -= 1


class Book:
    def __init__(self, a):
        self.min_heap = a[:]
        self.max_heap = [-x for x in a]
        heapq.heapify(self.min_heap)
        heapq.heapify(self.max_heap)

    def empty(self):
        return self.min() >= self.max()

    def min(self):
        if not self.min_heap:
            return float('inf')
        return self.min_heap[0]

    def max(self):
        if not self.max_heap:
            return -1
        return -self.max_heap[0]

    def evictMin(self):
        if not self.empty():
            heapq.heappop(self.min_heap)

    def evictMax(self):
        if not self.empty():
            heapq.heappop(self.max_heap)

 
def solve():
    n = int(input())
    a = list(map(int, input().split()))

    book = Book(a)
    l, r = 0, n - 1
    while not book.empty() and (a[l] == book.min() 
                            or a[l] == book.max() 
                            or a[r] == book.min() 
                            or a[r] == book.max()):

        if a[l] == book.min():
            book.evictMin()
            l += 1
        elif a[l] == book.max():
            book.evictMax()
            l += 1

        if a[r] == book.min():
            book.evictMin()
            r -= 1
        elif a[r] == book.max():
            book.evictMax()
            r -= 1

    if book.empty():
        print(-1)
    else:
        print(l + 1, r + 1)

t = int(input())

while t:
    solve()
    t -= 1
