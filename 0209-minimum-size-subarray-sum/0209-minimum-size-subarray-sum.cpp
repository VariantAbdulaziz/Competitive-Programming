class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int result = INT_MAX, window = 0;
        for(int r=0, l=0; r<nums.size(); r++){
            
            window += nums[r];
            while(window >= target){
                result = min(result, r - l + 1);
                window -= nums[l];
                l++;
            }
        }
        return result == INT_MAX? 0: result;
    }
};