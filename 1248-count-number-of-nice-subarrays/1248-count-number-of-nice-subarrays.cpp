class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, odds = 0;
        vector<int> book(n + 1);
        book[0]++;
        for(int i=0; i<n; i++) {
            odds += nums[i] % 2? 1: 0;
            ans += odds - k >= 0? book[odds - k]: 0;
            book[odds]++;
        }
        return ans;
    }
};