// source: https://leetcode.com/problems/top-k-frequent-elements/

// policy: frequency distribution | map | priority queue
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        priority_queue<pair<int, int>> maxH;
        map<int, int> freq;
        vector<int> ans;
        ans.reserve(k);
        
        for(auto val: nums)
            freq[val]++;
        
        for(auto [key, val]: freq)
            maxH.push({val, key});
        
        while(k > 0){
            ans.push_back(maxH.top().second); maxH.pop(); k--;
        }
        return ans;
    }
};