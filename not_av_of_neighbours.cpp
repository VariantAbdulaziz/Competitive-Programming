// source: https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/

// strategy: sorting
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        sort(
            nums.begin(),
            nums.end(),
            [](const int& a, const int&b){
                
                string sa = to_string(a);
                string sb = to_string(b);
                return sa + sb > sb + sa;
            }
        );
        
        if(nums[0]==0)
            return "0";
        
        string res = "";
        for(auto num: nums){
            
            res += to_string(num);
        }
        return res;
    }
};