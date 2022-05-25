// source: https://leetcode.com/problems/frequency-of-the-most-frequent-element/

// strategy: sort | prefix sum | sliding widnow
class Solution {
public:
    void prefixSum(const vector<int>& nums, vector<long long>& preSum){
        preSum[0] = 0;
        for(int i{}; i < nums.size(); i++){
            preSum[i + 1] = preSum[i] + nums[i];
        }
    }
    
    int maxFrequency(vector<int>& nums, int k) {
        
        vector<long long> preSum(nums.size() + 1);
        
        sort(nums.begin(), nums.end());
        prefixSum(nums, preSum);
        
        long long freq{}, l{}, r=1;
        while (r < preSum.size() ) {

            if((nums[r-1] * (r - l)) - (preSum[r] - preSum[l]) <= k){
                freq = max(freq, r - l);
                r++;
            }else {
                l++;
            }
                
        }
        
        return freq;
    }
};