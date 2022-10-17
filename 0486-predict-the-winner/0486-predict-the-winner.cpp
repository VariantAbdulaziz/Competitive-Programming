class Solution {
public:
    int dp(vector<vector<vector<int>>>& cache, vector<int>&nums, int l, int r, int turn){
            if(r < l) return 0;
            
            auto& res = cache[l][r][turn];
            if(res != -1) return res;
            if(turn) return max(nums[l] + dp(cache, nums, l+1, r, !turn), nums[r] + dp(cache, nums, l, r-1, !turn));
            
            return min(dp(cache, nums, l+1, r, !turn), dp(cache, nums, l, r-1, !turn));
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> cache(n, vector<vector<int>>(n, {-1, -1}));
        int total = 0;
        for(int ni: nums) total += ni;
        int score = dp(cache, nums, 0, n-1, 1);
        int anti_score = total - score;
        return score >= anti_score? true: false;
    }
};