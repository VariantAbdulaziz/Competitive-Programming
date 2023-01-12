class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(begin(nums), end(nums));
        long long score = 0;
        while(k--){
            int curr = pq.top();
            score += curr;
            pq.pop();
            pq.push(ceil(curr / 3.0));
        }
        return score;
    }
};