// source: https://leetcode.com/problems/find-original-array-from-doubled-array/

// policy: sorting | semaphores
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> original;
        original.reserve(changed.size()/2);
        map<int, int> waiting;
        
        sort(changed.begin(), changed.end());
        
        for(int i{}; i < changed.size(); i++){
            
            if(waiting.find(changed[i])!= waiting.end() && waiting[changed[i]] > 0)
                waiting[changed[i]]--;
            else{
                waiting[changed[i]*2]++;
                original.push_back(changed[i]);
            }
        }
        if (original.size() == changed.size()/2)
            return original;
        return {};
    }
};