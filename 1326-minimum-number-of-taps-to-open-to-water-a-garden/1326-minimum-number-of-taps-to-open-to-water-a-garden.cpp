class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp;
        dp.resize(n + 2, n + 1);
        dp[0] = 0;
        for(int i=0; i<=n; i++) {
            for(int j=max(0, i - ranges[i]); j < min(i + ranges[i], n); j++) {
                dp[j + 1] = min(dp[j + 1], dp[max(0, i - ranges[i])] + 1);
            }
        }
        return dp[n] <= n? dp[n]: -1;
    }
};