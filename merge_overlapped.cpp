// source: https://leetcode.com/problems/merge-intervals/submissions/

// strategy: sorting
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        vector<vector<int>> res;
        
        sort(
            intervals.begin(),
            intervals.end(),
            [](vector<int>& a, vector<int>& b){
                
                return a[0] < b[0];
            }
        );
        
        res.push_back(intervals[0]);
        for(int i = 1; i< n; i++){
            
            vector<int>& last = res[res.size() - 1];
            vector<int>& interval = intervals[i];
            if(last[1] >= interval[0])
                last[1] = last[1] > interval[1]? last[1]: interval[1];
            else
                res.push_back(interval);
        }
        
        return res;
    }
};