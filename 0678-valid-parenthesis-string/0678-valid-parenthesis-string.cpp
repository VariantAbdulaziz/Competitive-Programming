class Solution {
    bool helper(vector<vector<int>> &dp, string &s, int idx, int open) {
        int n = s.size();
        if (idx == n) {
            return open == 0? 1: 0;
        }
        auto &result = dp[idx][open];
        if(result != -1) return result;
        if (s[idx] == '(') {
            return helper(dp, s, idx + 1, open + 1);
        } else if (s[idx] == ')') {
            return open != 0 && helper(dp, s, idx + 1, open - 1);
        } else {
            result = helper(dp, s, idx + 1, open)
                    || helper(dp, s, idx + 1, open + 1)
                    || open && helper(dp, s, idx + 1, open - 1);
        }
        return result? 1: 0;
    }
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp;
        dp.resize(n + 1, vector<int>(n + 1, -1));
        return helper(dp, s, 0, 0);
    }
};