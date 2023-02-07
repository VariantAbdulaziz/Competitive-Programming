class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(rbegin(nums), rend(nums));
        return nums[k - 1];
    }
};