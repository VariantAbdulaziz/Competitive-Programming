class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        vector<long long> prefix(nums.size() + 1);
        for(int i=0; i<nums.size(); i++){
            prefix[i+1] = prefix[i] + nums[i];
        }
        deque<int> dq;
        dq.push_back(0);
        int result = INT_MAX;
        for(int r=1; r<=nums.size(); r++){
            while(!dq.empty() && prefix[r] - prefix[dq.front()] >= k){
                result = min(result, r - dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && prefix[r] <= prefix[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(r);
        }
        return result == INT_MAX? -1: result;
    }
};