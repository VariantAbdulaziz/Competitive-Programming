class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        priority_queue<vector<int>> window;
        for(int i=0; i<k-1; i++) window.push({nums[i], i});
        
        for(int l=0, r=k-1; r < nums.size(); l++, r++){
            window.push({nums[r], r});
            while(window.top()[1] < l){
                window.pop();
            }
            result.push_back(window.top()[0]);
        }
        return result;
    }
};