class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int result = 0, zeros_count = 0;
        for(int l = 0, r = 0; r < nums.size(); r++){
            zeros_count += nums[r] == 0? 1: 0;
            while(zeros_count == 2){
                zeros_count -= nums[l] == 0? 1: 0;
                l++;
            }
            result = max(result, r - l + 1 - zeros_count);
        }
        return result == nums.size()? result - 1: result;
    }
};