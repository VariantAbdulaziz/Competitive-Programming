class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        long long mask = 0;
        for(auto num: nums)
            mask ^= num;
        
        vector<int> result(2);
        
        long long ls_bit = mask & -mask;
        for(auto num: nums){
            
            if(num & ls_bit)
                result[0] ^= num;
            else
                result[1] ^= num;
        }
        return result;
    }
};