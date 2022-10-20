class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int _cur = 0, _result = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            
            _cur = max(nums[i], _cur + nums[i]);
            _result = max(_result, _cur);
        }
        return _result;
    }
};