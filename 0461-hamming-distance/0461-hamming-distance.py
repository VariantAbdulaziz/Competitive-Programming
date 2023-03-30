class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        N = 32
        result = 0
        for i in range(N):
            xi = 0 if x & (1 << i) == 0 else 1
            yi = 0 if y & (1 << i) == 0 else 1
            result += xi ^ yi
            
        return result