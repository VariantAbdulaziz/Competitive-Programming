class Solution {
public:
    void backtrack(int idx, vector<int> *cookies_ptr, vector<int> *slots_ptr, int *result_ptr) {
        auto &result = *result_ptr;
        auto &cookies = *cookies_ptr;
        auto &slots = *slots_ptr;
        if(idx == cookies.size()) {
            result = min(result, *max_element(begin(slots), end(slots)));
            return;
        }
        for(auto &slot: slots) {
            slot += cookies[idx];
            backtrack(idx + 1, &cookies, &slots, &result);
            slot -= cookies[idx];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> slots(k);
        int result;
        backtrack(0, &cookies, &slots, &result);
        return result;
    }
};