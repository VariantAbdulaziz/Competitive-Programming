class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curr = 0, result = INT_MIN, n = nums.size();
        vector<int> prefix(n + 1);
        
        for(int i=0; i<n; i++){
            curr = max(nums[i], curr + nums[i]);
            result = max(result, curr);
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int running = 0, max_suffix = INT_MIN;
        for(int i=n - 1; i>=0; i--){
            running += nums[i];
            max_suffix = max(max_suffix, running);
            result = max(result, max_suffix + prefix[i]);
        }
        
        return result;
    }
};