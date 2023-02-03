class Solution {
    vector<int> prefix;
public:
    Solution(vector<int>& w) {
        int N = w.size();
        prefix.resize(N + 1);
        for(int i=0; i<N; i++){
            prefix[i + 1] = prefix[i] + w[i];
        }
    }
    
    int pickIndex() {
        int mod = prefix.back();
        int index = upper_bound(begin(prefix), end(prefix), rand() % mod) - begin(prefix);
        return index - 1; // the -1 to account for the first index with a value of zero to conduct the prefix sum
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */