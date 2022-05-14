// source: https://leetcode.com/problems/find-target-indices-after-sorting-array/submissions/

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        
        #define SIZE 101
        int n = nums.size();
        int count = 0;
        int lessThan = 0;
        
        for(int i{}; i < n; i++){
            
            if(nums[i]<target) lessThan++;
            else if(nums[i] == target) count++;
        }
        
        vector<int> res(count);
        
        if(count)
            res[0] = lessThan;
        
        for(int i = 1; i < count; i++){
            res[i] = res[i - 1] + 1;
        }
        
        return res;
    }
};