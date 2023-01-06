class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        res = summ = i = 0
        while i < len(costs) and summ + costs[i] <= coins:
            res += 1
            summ += costs[i]
            i += 1
            
        return res