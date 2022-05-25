// solution: https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/submissions/

// strategy: sorting
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        
        sort(nums.begin(),
             nums.end(),
             [](auto& a, auto& b){
                if (a.size() == b.size()) {
                    for (auto i = 0; i < a.size(); ++i) {
                        if (a[i] == b[i])
                            continue;
                        return a[i] > b[i];
                    }
                }
                return a.size() > b.size();
             }
        );
        return nums[k - 1];
    }
};