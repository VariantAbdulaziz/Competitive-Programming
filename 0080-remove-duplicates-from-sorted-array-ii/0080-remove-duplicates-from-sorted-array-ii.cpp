class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int holder = 0, seeker = 0, N = nums.size();
        while (seeker < N) {
            nums[holder] = nums[seeker];
            int count = 0, advanced = holder;
            while(seeker < N && nums[seeker] <= nums[holder]){
                if(count < 2) {
                    nums[advanced++] = nums[seeker];
                    count++;
                }
                seeker++;
            }
            holder = advanced;
        }
        return holder;
    }
};