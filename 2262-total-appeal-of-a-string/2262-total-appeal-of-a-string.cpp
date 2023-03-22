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
            
            int appeal = 0;
            for(int k=26, itr=1; k>0; k--, itr++) {
                appeal += itr * (values[k] - values[k-1]);
            }
            appeal_sum += appeal;
        }
        return appeal_sum;
    }
};
