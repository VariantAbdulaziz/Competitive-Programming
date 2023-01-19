class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> count(k);
        count[0] = 1;
        int prefix = 0, result = 0;
        for(auto num: nums){
            prefix += num;
            int moded = (prefix % k + k) % k;
            result += count[moded];
            count[moded]++;
        }
        return result;
    }
};