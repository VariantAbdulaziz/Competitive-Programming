class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        
        map<int, int> window;
        for(int r=0; r<nums.size(); r++){
            int l = r - indexDiff - 1;
            if(l >= 0 && window[nums[l]] == l) window.erase(nums[l]);
            
            auto down_pos = window.lower_bound(nums[r] - valueDiff);
            auto up_pos = window.lower_bound(nums[r] + valueDiff);
            
            if(down_pos != window.end() && abs((long long)(*down_pos).first - nums[r]) <= valueDiff) return true;
            if(up_pos != window.end() && abs((long long)(*up_pos).first - nums[r]) <= valueDiff) return true;
            window[nums[r]] = r;
        }
        return false;
    }
};