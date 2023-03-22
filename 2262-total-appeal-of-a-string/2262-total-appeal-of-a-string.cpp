class Solution {
public:
    long long appealSum(string s) {
        int n = s.size();
        long long appeal_sum = 0;
        vector<int> book(27, -1);
        for(int i=0; i<n; i++) {
            book[s[i] - 'a'] = i;
            vector<int> values = book;
            sort(begin(values), end(values));
            
            for(int k=26, appeal=1; k>0; k--, appeal++) {
                appeal_sum += appeal * (values[k] - values[k-1]);
            }
        }
        return appeal_sum;
    }
};
