#include <algorithm>

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long result = 0, prev = -1, min_l = -1, max_l = -1, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] < minK || nums[i] > maxK) prev = i;
            if (nums[i] == minK) min_l = i;
            if (nums[i] == maxK) max_l = i;
            int now = min(min_l, max_l) - prev;
            if (now > 0)
                result += now;
        }
        return result;
    }
};