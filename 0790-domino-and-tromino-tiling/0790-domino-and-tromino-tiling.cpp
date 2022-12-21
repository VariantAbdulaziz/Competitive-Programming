class Solution {
public:
    int numTilings(int n) {
        const int mod = 1e9 + 7;
        long curr_full = 1, curr_partial = 0;
        long next_full = 0, next_partial = 0, next_next_partial = 0, next_next_full = 0;
        for(int i=0; i<n; i++){
            curr_full %= mod;
            curr_partial %= mod;
            next_full += curr_full;
            next_next_full += curr_full;
            next_full += curr_partial;
            next_next_partial += 2 * curr_full;
            next_partial += curr_partial;
            
            curr_full = next_full;
            next_full = next_next_full;
            next_next_full = 0;
            curr_partial = next_partial;
            next_partial = next_next_partial;
            next_next_partial = 0;
        }
        return curr_full % mod;
    }
};