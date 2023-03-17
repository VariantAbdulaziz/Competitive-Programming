class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        path = []
        def combination(_sum, idx):
            if _sum == target:
                result.append(path[:])
                return
            if idx == len(candidates) or _sum > target:
                return
            path.append(candidates[idx])
            combination(_sum + candidates[idx], idx)
            path.pop()
            combination(_sum, idx + 1)
        
        combination(0, 0)
        return result