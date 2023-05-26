class Solution:
    def reverse(self, x: int) -> int:
        if x == 0: return x
        sign = x // abs(x)
        x = abs(x)
        strx = str(x)
        result = int(strx[::-1])
        result = sign * result
        if result < -2**31 or result > (2**31 - 1):
            result = 0
        return result