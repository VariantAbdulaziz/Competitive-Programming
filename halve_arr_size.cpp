// source: https://leetcode.com/problems/reduce-array-size-to-the-half/submissions/

// policy: frequency distribution
class Solution {
public:
    #define MAX_ARR_ELEM 100'001
    int minSetSize(vector<int>& arr) {
        vector<int> freq(MAX_ARR_ELEM, 0);
        
        for(auto x: arr)
            freq[x]++;
        
        sort(
            freq.begin(),
            freq.end(),
            [](auto& l, auto& r){
                return l > r;
            }
        );
        int cur_sum = 0;
        for(int i{}; i < freq.size(); i++){
            cur_sum += freq[i];
            if (cur_sum >= arr.size()/2)
                return i + 1;
        }
        return 0;
    }
};