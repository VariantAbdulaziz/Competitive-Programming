class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, odds = 0;
        map<int, int> book;
        book[0]++;
        for(int i=0; i<n; i++) {
            odds += nums[i] % 2? 1: 0;
            ans += book[odds - k];
            book[odds]++;
        }
        return ans;
    }
};