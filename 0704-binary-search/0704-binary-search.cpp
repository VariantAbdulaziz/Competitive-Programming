class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto result = lower_bound(begin(nums), end(nums), target);
        if(result == end(nums) || *result != target) return -1;
        return result - begin(nums);
    }
};