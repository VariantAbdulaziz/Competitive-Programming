// source: https://leetcode.com/problems/max-number-of-k-sum-pairs/

// strategy: sorting | two pointers
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        int l{}, r = nums.size() - 1, ans{};
        while(l < r){
            if(nums[r] + nums[l] == k){
                ans++;
                l++;
                r--;
            }
            else if(nums[r] + nums[l] < k) l++;
            else r--;
        }
        return ans;
    }
};