class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<map<int, int>> dp;
        dp.resize(n + 1);
        int result = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(dp[i].find(nums[j] - nums[i]) != dp[i].end())
                    dp[j][nums[j] - nums[i]] = dp[i][nums[j] - nums[i]] + 1;
                else dp[j][nums[j] - nums[i]] = 2; 
                result = max(result, dp[j][nums[j] - nums[i]]);
            }
        }
        return result;
    }
};