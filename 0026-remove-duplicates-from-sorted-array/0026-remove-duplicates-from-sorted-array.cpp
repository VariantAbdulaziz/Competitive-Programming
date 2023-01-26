class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int N = nums.size(), holder = 0;
        for(int seeker = 0; seeker < N; holder++){
            nums[holder] = nums[seeker];
            while (seeker < N && nums[seeker] <= nums[holder]) {
                seeker++;
            }
        }
        return holder;
    }
};