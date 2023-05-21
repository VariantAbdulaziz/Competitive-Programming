class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size(), result = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int l = 0; l <= n; l++) {
            for (int r = 0; r <= m; r++) {
                result = max(result, dp[l][r]);
                if(l == n || r == m) continue;
                if (text1[l] == text2[r]) {
                    dp[l+1][r+1] = max(dp[l+1][r+1], dp[l][r] + 1);
                }
                dp[l+1][r] = max(dp[l+1][r], dp[l][r]);
                dp[l][r+1] = max(dp[l][r+1], dp[l][r]);
            }
        }
        return result;
    }
};