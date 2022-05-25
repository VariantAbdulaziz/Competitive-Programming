// source: https://leetcode.com/problems/pascals-triangle-ii/

// strategy: recursion
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0) return {1};
        vector<int> before = getRow(rowIndex - 1);
        vector<int> res{1};
        for(int i = 0; i < before.size() - 1; i++){
            res.push_back(before[i] + before[i+1]);
        }
        res.push_back(1);
        return res;
    }
};