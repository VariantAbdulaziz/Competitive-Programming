class Solution {
public:
    void backtrack(int start, int n, int k, vector<vector<int>> &result, vector<int> &slots) {
        if (slots.size() == k) {
            result.push_back(slots);
            return;
        } else if (n < start) return;
        
        slots.push_back(start);
        backtrack(start + 1, n, k, result, slots);
        slots.pop_back();
        backtrack(start + 1, n, k, result, slots);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> slots;
        backtrack(1, n, k, result, slots);
        return result;
    }
};