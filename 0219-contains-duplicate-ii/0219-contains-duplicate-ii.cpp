class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        set<int> window;
        for(int r=0; r<nums.size(); r++){
            int l = r - k - 1;
            if(l >= 0) window.erase(nums[l]);
            if(window.find(nums[r]) != window.end()) return true;
            window.insert(nums[r]);
        }
        return false;
    }
};