class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        // base case
        dp[0][0] = 1;
        
        for(int row = 0; row < m; row++){
            
            for(int col = 0; col < n; col++){ // fix the state
                
                if((row + 1) < m){
                    dp[row + 1][col] += dp[row][col];
                }
                if((col + 1) < n){
                    dp[row][col + 1] += dp[row][col];
                }
            }
        }
        return dp[m-1][n-1];
    }
};