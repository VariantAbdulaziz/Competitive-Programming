class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> result;
        priority_queue<int, vector<int>, greater<>> q;
        for(auto num: nums) q.push(num);
        while(!q.empty()) {
            result.push_back(q.top());
            q.pop();
        }
        return result;
    }
};