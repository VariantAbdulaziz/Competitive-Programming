class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        if n == 1:
            return 0
        row = 2**(n-1)
        if 2 * k <= row:
            return self.kthGrammar(n-1, k)
        
        return 1-self.kthGrammar(n-1, k - row/2)