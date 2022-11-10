class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        // if the array nums can be changed temporarily
        int duplicate;
        for(auto num: nums){
            if(nums[abs(num) - 1] > 0){
                nums[abs(num) - 1] *= -1;
            } else {
                duplicate = abs(num);
            }
        }
        
        int missing;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < 0){
                nums[i] *= -1;
            } else {
                missing = i + 1;
            }
        }
        return {duplicate, missing};
    }
};