class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int N = nums.size();
        sort(begin(nums), end(nums));        
        int already_substracted = 0, minimum_operations = 0;
        for(int i = 0; i < N; i++) {
            int x = nums[i] - already_substracted;
            if(x > 0) {
                minimum_operations++;
            }
            already_substracted += x;
        }
        return minimum_operations;
    }
};