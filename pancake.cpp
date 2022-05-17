// source: https://leetcode.com/problems/pancake-sorting/

// policy: dictionary
class Solution {
public:
    void flip(vector<int>& dict, int flipper){
        
        for(int i = 1; i < dict.size(); i++){
            if(dict[i] <= flipper) dict[i] = flipper - dict[i];
        }
    }
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> dict(arr.size()+1, 0);
        vector<int> ans;
        
        for(int i{}; i < arr.size(); i++){
            dict[arr[i]] = i;
        }
        
        for(int i = dict.size() - 1; i > 0 ; i--){
            
            ans.push_back(dict[i]+1);
            flip(dict, dict[i]);
            ans.push_back(i);
            flip(dict, i - 1);
        }
        return ans;
    }
};