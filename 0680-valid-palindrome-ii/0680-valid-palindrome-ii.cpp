class Solution {
public:
    bool validPalindrome(string s) {
        // a
        int N = s.size(), lcount = 0, rcount = 0;
        for(int l=0, r=N-1; l < r; l++, r--) {
            if(s[l] != s[r]) {
                l--;
                rcount++;
            }
        }
        for(int l=0, r=N-1; l < r; l++, r--) {
            if(s[l] != s[r]) {
                r++;
                lcount++;
            }
        }
        return lcount < 2 || rcount < 2;
    }
};