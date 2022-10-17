class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> cache(n, vector<vector<int>>(n, {-1, -1}));
        auto dp = [&](auto&& dp, int l, int r, int turn){
            if(r < l) return 0;
            
            auto& res = cache[l][r][turn];
            if(res != -1) return res;
            if(turn) return max(nums[l] + dp(dp, l+1, r, !turn), nums[r] + dp(dp, l, r-1, !turn));
            
            return min(dp(dp, l+1, r, !turn), dp(dp, l, r-1, !turn));
        };
        int total = 0;
        for(int ni: nums) total += ni;
        int score = dp(dp, 0, n-1, 1);
        int anti_score = total - score;
        return score >= anti_score? true: false;
    }
};