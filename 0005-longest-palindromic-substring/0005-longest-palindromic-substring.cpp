class Solution {
public:
    string longestPalindrome(string s) {
        int global_len = 0, global_l = 0, n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int len=1; len <= n; len++) {
            for (int l=0; l + len <= n; l++) {
                int r = l + len - 1;
                dp[l][r] = (l + 1 >= r || dp[l+1][r-1]) && s[l] == s[r];
                if(len > global_len && dp[l][r]) {
                    global_l = l;
                    global_len = len;
                }
            }
        }
        string result = s.substr(global_l, global_len);
        return result;
    }
};