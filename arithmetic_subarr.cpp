// source: https://leetcode.com/problems/arithmetic-subarrays/submissions/

// policy: iterative
class Solution {
public:
    bool isArithmetic(vector<int>& nums){
        
        if(nums.size() < 2) return true;
        int d = nums[1] - nums[0];
        for(int i{}; i< nums.size() - 1; i++){
            if (nums[i + 1] - nums[i] != d) return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<int> avec;
        vector<bool> res(l.size());
        for(int i{}; i < l.size(); i++){
            
            for(int j=l[i]; j <= r[i]; j++){
                avec.push_back(nums[j]);
            }
            sort(avec.begin(), avec.end());
            res[i] = isArithmetic(avec);
            avec.clear();
            
        }
        
        return res;
    }
};