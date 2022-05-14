// source: https://leetcode.com/problems/sort-colors/submissions/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        #define SIZE 3
        int n = nums.size();
        vector<int> counts(SIZE);
        
        for(int i{}; i < n; i++){
            
            counts[nums[i]]++;
        }
        
        int j = 0;
        for(int i{}; i < SIZE; i++){
            
            int cur = counts[i];
            while(cur > 0 && j < n){
                nums[j] = i;
                j++;
                cur--;
            }
        }
    }
};