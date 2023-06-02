class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        cache = {}
        def dp(idx, ttype):
            if idx < 0 and ttype == -1:
                return float("-inf")
            
            elif idx < 0:
                return 0
            
            state = (idx, ttype)
            if state in cache:
                return cache[state]
            
            cache[state] = float('-inf') if ttype != 1 else 0
            cache[state] = max(cache[state], dp(idx-1, -ttype) + (-fee if ttype == 1 else 0) + ttype * prices[idx])
            cache[state] = max(cache[state], dp(idx-1, ttype))
                
            return cache[state]
        
        result = 0
        for i in range(len(prices)):
            result = max(result, dp(i, 1))
        

        return result