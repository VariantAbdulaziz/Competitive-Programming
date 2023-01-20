class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> window;
        
        for(int r=0; r < nums.size(); r++){
            while(!window.empty() && nums[window.back()] <= nums[r])
                window.pop_back();
            window.push_back(r);
            if(window.front() < r - k + 1) window.pop_front();
            if(r >= k-1) result.push_back(nums[window.front()]);
        }
        return result;
    }
};