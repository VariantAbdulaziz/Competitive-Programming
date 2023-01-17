class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> ones(n + 1), zeroes(n + 1);
        for(int i=0; i<n; i++){
            ones[i + 1] = ones[i] + (s[i] - '0');
        }
        
        for(int i=n - 1; i >= 0; i--){
            zeroes[i] = zeroes[i + 1] + ('1' - s[i]);
        }
        int min_flips = min(ones[n], zeroes[0]);
        for(int i=0; i<n; i++){
            min_flips = min(min_flips, ones[i] + zeroes[i]);
        }
        return min_flips;
    }
};