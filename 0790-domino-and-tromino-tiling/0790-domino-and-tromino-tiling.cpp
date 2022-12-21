class Solution {
public:
    int numTilings(int n) {
        const int mod = 1e9 + 7;
        vector<long> full(n + 2), partial(n + 2);
        full[0] = 1;
        for(int i=0; i<n; i++){
            full[i] %= mod;
            partial[i] %= mod;
            full[i + 1] += full[i];
            full[i + 2] += full[i];
            full[i + 1] += partial[i];
            partial[i + 2] += 2 * full[i];
            partial[i + 1] += partial[i];
        }
        return full[n] % mod;
    }
};