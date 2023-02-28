class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), result = 0;
        const int inf = 1e9;
        vector<vector<int>> dp;
        dp.resize(n + 1, vector<int>(m + 1));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i - 1 >= 0 && j - 1 >= 0)
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                dp[i][j] += matrix[i][j] == '1'? 1: 0;
                dp[i][j] = matrix[i][j] == '1'? dp[i][j]: 0;
                result = max(result, dp[i][j]);
            }
        }
        return result * result;
    }
};