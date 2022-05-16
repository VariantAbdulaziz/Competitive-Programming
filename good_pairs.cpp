// source: https://leetcode.com/problems/number-of-good-pairs/submissions/

// policy: semaphores
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int> aDict;
        int answer{};
        
        for(int i{}; i < nums.size(); i++){
            
            if(aDict.find(nums[i]) != aDict.end())
                answer+=aDict[nums[i]];
            aDict[nums[i]]++;
        }
        
        return answer;
    }
};