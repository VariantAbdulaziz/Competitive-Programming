class Solution:
    def myPow(self, x: float, n: int) -> float:
        # pow(n) = n * pow(n - 1)
        # temp = pow(n // 2)
        # pow(n) = temp * temp * pow(n % 2)
        
        if n == 0:
            return 1
        if n == 1:
            return x
        
        if n < 0:
            return 1 / self.myPow(x, abs(n))
        
        temp = self.myPow(x, n // 2)
        return temp * temp * self.myPow(x, n % 2)
        
        
        
        