class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int N = nums.size(), result = 0;
        deque<int> max_win, min_win;
        for(int r=0, l=0; r<N; r++){
            while(!max_win.empty() && nums[max_win.back()] < nums[r]){
                max_win.pop_back();
            }
            while(!min_win.empty() && nums[min_win.back()] > nums[r]){
                min_win.pop_back();
            }   
            max_win.push_back(r);
            min_win.push_back(r);
            while(nums[max_win.front()] - nums[min_win.front()] > limit){
                if(max_win.front() < min_win.front()) {
                    l = max(l, max_win.front() + 1);
                    max_win.pop_front();
                }
                else {
                    l = max(l, min_win.front() + 1);
                    min_win.pop_front();
                }
            }
            result = max(result, r - l + 1);
        }
        return result;
    }
};