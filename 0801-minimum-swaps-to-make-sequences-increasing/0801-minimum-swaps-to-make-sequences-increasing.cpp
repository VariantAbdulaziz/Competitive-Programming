class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n, vector<int>(2, n + 1));
        dp[0][0] = dp[0][1] = 0;
        for (int i = 0; i < n; i++) {
            for (int is_swapped = 0; is_swapped < 2; is_swapped++) {
                int a = nums1[i], b = nums2[i];
                if (is_swapped) {
                    swap(a, b);
                }
                if(i + 1 < n && a < nums1[i + 1] && b < nums2[i + 1]) {
                    dp[i + 1][0] = min(dp[i + 1][0], dp[i][is_swapped] + is_swapped);
                }
                if(i + 1 < n && a < nums2[i + 1] && b < nums1[i + 1]) {
                    dp[i + 1][1] = min(dp[i + 1][1], dp[i][is_swapped] + is_swapped);
                }
            }
        }
        return min(dp[n - 1][0], dp[n - 1][1] + 1);
    }
};