class Solution {
public:
    int firstUniqChar(string s) {
        int holder = 0, n = s.size();
        map<char, int> freq;
        for(int r=0; r<n; r++) {
            freq[s[r]]++;
            while(holder < n && freq[s[holder]] > 1) {
                holder++;
            }
        }
        return holder == n? -1: holder;
    }
};