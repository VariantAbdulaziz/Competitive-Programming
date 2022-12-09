class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        cost.emplace_back(0);
        cost.emplace_back(0);
        vector<int> dp(n + 2, INT_MAX);
        dp[0] = 0;
        for(int i=0; i<n; i++){
            if(i+1 <= (n + 1)) dp[i+1] = min(dp[i+1], dp[i] + cost[i]);
            if(i+2 <= (n + 1)) dp[i+2] = min(dp[i+2], dp[i] + cost[i+1]);
        }
        return min(dp[n], dp[n+1]);
    }
};