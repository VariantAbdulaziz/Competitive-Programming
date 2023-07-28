class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        l = 0
        expiv = -2
        longest = 1
        comp = lambda x, y: 1 if x > y else 0 if x == y else -1
        inv = lambda x: 1 if x == -1 else -2 if x == 0 else -1
        for r in range(1, len(arr)):
            iv = comp(arr[r], arr[r - 1])
            if iv != expiv and iv != 0:
                l = r - 1
            elif iv == 0:
                l = r
            
            longest = max(longest, r - l + 1)
            expiv = inv(iv)
            
        return longest
            