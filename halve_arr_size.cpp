// source: https://leetcode.com/problems/reduce-array-size-to-the-half/submissions/

// policy: frequency distribution | priority queue
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freq;
        priority_queue<int> maxH;
        
        for(auto val: arr)
            freq[val]++;
        
        for(auto [key, val]: freq)
            maxH.push(val);
        
        int preFreqSum = 0, minSetLen = 0;
        while(preFreqSum < arr.size()/2 && !maxH.empty()){
            minSetLen++;
            preFreqSum += maxH.top(); maxH.pop();
        }
        return minSetLen;
    }
};