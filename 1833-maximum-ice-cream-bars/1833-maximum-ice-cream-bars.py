class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        res = i = 0
        while i < len(costs) and coins - costs[i] >= 0:
            res += 1
            coins -= costs[i]
            i += 1
            
        return res