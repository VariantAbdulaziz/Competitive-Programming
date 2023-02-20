class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int _min = nums[0];
        int result = 0;
        int n = nums.size();
        for(int i=1; i<n; i++){
            result = max(result, nums[i] - _min);
            _min = min(_min, nums[i]);
        }
        return result? result: -1;
    }
};