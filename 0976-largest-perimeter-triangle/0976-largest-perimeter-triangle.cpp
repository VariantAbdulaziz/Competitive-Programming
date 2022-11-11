class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(begin(nums), end(nums), greater<int>());
        
        for(int i=0; i<=max((int)nums.size()-3, 0); i++){
            if((nums[i+2] + nums[i+1]) > nums[i])
                return nums[i+2] + nums[i+1] + nums[i];
        }
        return 0;
    }
};