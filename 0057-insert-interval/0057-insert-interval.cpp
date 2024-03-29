class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(begin(intervals), end(intervals), [](auto a, auto b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        vector<vector<int>> result;
        for(auto interval : intervals){
            if(!result.empty() && interval[0] <= result.back()[1]){
                result.back()[1] = max(interval[1], result.back()[1]);
            } else {
                result.push_back(interval);
            }
        }
        return result;
    }
};