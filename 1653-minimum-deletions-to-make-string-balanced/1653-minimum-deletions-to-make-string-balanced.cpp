class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> suffix;
        suffix.resize(n + 1);
        
        for(int i=n; i>0; i--){
            suffix[i-1] = suffix[i] + (s[i-1] == 'a'? 1: 0);
        }
        int result = n;
        int untilnow = 0;
        for(int i=0; i<=n; i++) {
            result = min(result, untilnow + suffix[i]);
            if(i < n) untilnow += (s[i] == 'b'? 1: 0);
        }
        return result;
    }
};