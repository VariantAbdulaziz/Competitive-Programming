class Solution {
public:
    int backtrack(vector<int>& nums, int prev) {
        if(nums.empty()) return 1;
        
        int result = 0, n = nums.size();
        for(int i=0; i<n; i++) {
            int temp = nums[i];
            int s;
            if (prev != -1) s = sqrt(prev + temp);
            auto another = nums;
            another.erase(another.begin() + i);
            if(i > 0 && nums[i - 1] == temp || (prev != -1 && (s * s != (prev + temp))))
               continue;
            
            result += backtrack(another, temp);
        }
        return result;
    }
    int numSquarefulPerms(vector<int>& nums) {
        sort(begin(nums), end(nums));
        
        return backtrack(nums, -1);
    }
};