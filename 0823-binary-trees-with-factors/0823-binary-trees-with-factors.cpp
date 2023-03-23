class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long n = arr.size(), ans = 0;
        map<int, long> book;
        
    
        sort(begin(arr), end(arr));
        for (int i=0; i<n; i++) {
            book[arr[i]] = 1;
            for(int j=0; j<n; j++) {
                if(arr[i] % arr[j] == 0)
                    book[arr[i]] += book[arr[j]] * book[arr[i] / arr[j]] % MOD;
            }
            ans += book[arr[i]] % MOD;
        }
        return ans % MOD;
    }
};