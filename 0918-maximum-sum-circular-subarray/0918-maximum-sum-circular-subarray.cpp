class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int result = INT_MIN, cur = 0;
        for(int num: nums){
            cur = max(cur + num, num);
            result = max(result, cur);
        }
        vector<int> prefix(nums.size() + 1), suffix(nums.size() + 1);
        for(int i = 0; i < nums.size(); i++){
            prefix[i+1] = prefix[i] + nums[i];
        }
        int max_back = INT_MIN;
        for(int i = nums.size() -1; i >= 0; i--){
            suffix[i] = suffix[i+1] + nums[i];
            max_back = max(max_back, suffix[i]);
            result = max(result, max_back + prefix[i]);
        }
        return result;
    }
};