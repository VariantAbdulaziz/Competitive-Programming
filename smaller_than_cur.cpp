// source: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/submissions/

// strategy: prefix sum
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        #define SIZE 101
        int n = nums.size();
        vector<int> count(SIZE, 0);
        vector<int> preSum(SIZE + 1, 0);
        vector<int> res(n);
        
        for(int i{}; i < n; i++){
            count[nums[i]]++;
        }
        
        for(int i{}; i < SIZE; i++){
            preSum[i+1] = preSum[i] + count[i];
        }
        
        for(int i{}; i < n; i++){
            res[i] = preSum[nums[i]];
        }
        
        return res;
    }
};