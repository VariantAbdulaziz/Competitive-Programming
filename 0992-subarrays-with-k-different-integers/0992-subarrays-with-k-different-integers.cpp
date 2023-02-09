class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        map<int, int> freql, freqll;
        int n = nums.size(), uniquel = 0, uniquell = 0, subarrays_with_k_distinct = 0;
        for(int r=0, l=0, ll=0; r<n; r++) {
            freql[nums[r]]++;
            freqll[nums[r]]++;
            if(freql[nums[r]] == 1) uniquel++;
            if(freqll[nums[r]] == 1) uniquell++;
            
            while(uniquel > k && l <= r) {
                freql[nums[l]]--;
                if(freql[nums[l]] == 0) {
                    uniquel--;
                }
                l++;
            }
            while(uniquell >= k && ll <= r) {
                freqll[nums[ll]]--;
                if(freqll[nums[ll]] == 0) {
                    uniquell--;
                }
                ll++;
            }
            subarrays_with_k_distinct += ll - l;
        }
        return subarrays_with_k_distinct;
    }
};