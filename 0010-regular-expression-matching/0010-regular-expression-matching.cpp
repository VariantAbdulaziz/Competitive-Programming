class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        deque<deque<bool>> dp(n + 2, deque<bool>(m + 2, false));
        dp[0][0] = true;
        for(int i = 0; i <= n; i++){
            for (int j = 0; j < m; j++){ // fix the state
                if(i == n && j + 1 < m  && p[j + 1] == '*'){
                    dp[i][j + 2] = dp[i][j + 2] || dp[i][j];
                    continue;
                }
                
                bool match = (p[j] == '.' || s[i] == p[j]);
                if (j + 1 < m && p[j + 1] == '*') {
                    dp[i][j + 2] = dp[i][j + 2] || dp[i][j];
                    dp[i + 1][j] = dp[i + 1][j] || (dp[i][j] && match);
                } else {
                    dp[i + 1][j + 1] = dp[i + 1][j + 1] || (dp[i][j] && match);
                }
            }
        }
        return dp[n][m];
    }
};