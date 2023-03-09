class Solution {
public:
    void backtrack(int idx, int start, int n, vector<vector<int>> &result, vector<int> &slots) {
        if (idx == slots.size()) {
            result.push_back(slots);
            return;
        }
        for(int i=start; i<=n; i++) {
            slots[idx] = i;
            backtrack(idx + 1, i + 1, n, result, slots);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> slots(k);
        backtrack(0, 1, n, result, slots);
        return result;
    }
};