class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        def dfs(l, r, t):
            if l > r:
                return 0
            
            if t:
                return max(nums[l] + dfs(l + 1, r, not t), nums[r] + dfs(l, r - 1, not t))
            
            return min(dfs(l + 1, r, not t), dfs(l, r - 1, not t))
        
        player_1_score = dfs(0, len(nums) - 1, True)
        total_score = sum(nums)
        player_2_score = total_score - player_1_score
        
        return player_1_score >= player_2_score