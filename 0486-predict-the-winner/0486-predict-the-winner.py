class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        dp = {}

        def get_score(i, j, turn = 1):
            if i > j:
                return 0
            if (i, j, turn) in dp:
                return dp[(i,j, turn)]
            if turn == 1:
                score = max(get_score(i + 1, j, 0) + nums[i], get_score(i, j - 1, 0  ) + nums[j] )
            else:   
                score = min(get_score(i + 1,j, 1),get_score(i, j - 1, 1))
            dp[(i, j, turn)] = score
            return score
        
        total = sum(nums)
        player1 = get_score(0, len(nums) - 1)
        player2 = total -  player1
        return player1 >= player2
