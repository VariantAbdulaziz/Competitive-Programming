class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0, n = nums.size();
        for(int j=(n + 1)/2; j>0; j/=2) {
            while(s + j < n && nums[s + j] <= target) s += j;
        }
        return target <= nums[s]? s: s + 1;
    }
};