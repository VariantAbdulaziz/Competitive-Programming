class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<>> q(begin(nums), end(nums));
        
        int already_substracted = 0, minimum_operations = 0;
        while(!q.empty()) {
            int x = q.top() - already_substracted;
            q.pop();
            if(x > 0) {
                minimum_operations++;
            }
            already_substracted += x;
        }
        return minimum_operations;
    }
};