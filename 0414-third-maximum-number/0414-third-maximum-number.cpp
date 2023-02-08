class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(rbegin(nums), rend(nums));
        int pivot = 0, n = nums.size();
        for(int seeker = 0; seeker < n; pivot++) {
            nums[pivot] = nums[seeker];
            while(seeker < n && nums[seeker] >= nums[pivot]) {
                seeker++;
            }
        }
        return 2 < pivot? nums[2]: nums[0];
    }
};