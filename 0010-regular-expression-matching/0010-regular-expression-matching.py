class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        dp = [[False] * (n+1) for _ in range(m+1)]
        dp[0][0] = True

        for i in range(m+1):
            for j in range(1, n+1):
                if j > 1 and p[j-1] == '*':
                    dp[i][j] = dp[i][j-2] or (i > 0 and (p[j-2] == '.' or s[i-1] == p[j-2]) and dp[i-1][j])
                else:
                    dp[i][j] = i > 0 and dp[i-1][j-1] and (p[j-1] == '.' or s[i-1] == p[j-1])

        return dp[m][n]