// source: https://leetcode.com/problems/k-closest-points-to-origin/

// strategy: sorting
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector< vector<int> > res(k);
        
        sort(
            points.begin(),
            points.end(),
            [](const vector<int>& a, const vector<int>& b){
                
                return a[0]*a[0] + a[1]*a[1] < b[0] * b[0] + b[1] * b[1];
            }
        );
        
        for(int i{}; i < k; i++){
            
            res[i] = points[i];
        }
        
        return res;
    }
};