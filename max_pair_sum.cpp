// source: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/

// strategy: sorting | two pointers
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int maxSum = nums[0] + nums[nums.size() - 1];
        for(int i{}; i < nums.size()/2; i++){
            maxSum = max(maxSum, nums[i] + nums[nums.size() - 1 - i]);
        }
        return maxSum;
    }
};