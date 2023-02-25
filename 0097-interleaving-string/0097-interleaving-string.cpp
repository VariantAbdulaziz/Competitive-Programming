class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        vector<vector<bool>> dp;
        dp.resize(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
   
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=m; j++) {
                if (i < n)
                    dp[i + 1][j] = dp[i + 1][j] || (dp[i][j] && s1[i] == s3[i + j]);
                if(j < m)
                    dp[i][j + 1] = dp[i][j + 1] || (dp[i][j] && s2[j] == s3[i + j]);
            }
        }
        return m + n == s3.size() && dp[n][m];
    }
};