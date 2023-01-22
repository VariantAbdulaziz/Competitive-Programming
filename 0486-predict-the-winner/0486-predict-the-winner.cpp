

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int32_t N = nums.size();
        vector<vector<vector<int32_t>>> dp(N, vector<vector<int32_t>>(N, {0, 0}));
        for(int len = 1; len <= N; len++){
            for(int l = 0; l + len <= N; l++){
                for(int turn = 0; turn < 2; turn++){
                    int r = l + len - 1;
                    if(l == r){
                        dp[l][r][turn] = turn? nums[l]: 0;
                    } else if (turn){
                        dp[l][r][turn] = max(nums[l] + dp[l+1][r][!turn], nums[r] + dp[l][r-1][!turn]);
                    } else{
                        dp[l][r][turn] = min(dp[l+1][r][!turn], dp[l][r-1][!turn]);
                    }
                }
            }
        }
        int32_t total = 0;
        for(auto num: nums) total += num;
        int32_t player_one_score = dp[0][N-1][1];
        int32_t player_two_score = total - player_one_score;
        return player_one_score >= player_two_score;
    }
};