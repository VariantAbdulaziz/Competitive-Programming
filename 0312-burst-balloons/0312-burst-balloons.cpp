class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp;
        dp.resize(n + 1, vector<int>(n + 1));
        
        for(int len = 0; len < n; len++) {
            for(int l = 0; l + len < n; l++) {
                int r = l + len;

                for(int i=l; i<=r; i++) {
                    int coins = (l - 1 < 0? 1: nums[l - 1]) * nums[i] * (r + 1 == n? 1: nums[r + 1]);
                    coins += (i - 1 < 0? 0: dp[l][i - 1]) + (i + 1 == n? 0: dp[i + 1][r]);
                    dp[l][r] = max(dp[l][r], coins);
                }
            }
        }
        return dp[0][n - 1];
    }
};