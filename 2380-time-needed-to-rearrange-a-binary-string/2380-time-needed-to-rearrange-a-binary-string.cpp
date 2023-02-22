class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        bool swaps;
        int time = 0, n = s.size();
        do {
            swaps = false;
            for(int l=0, r=1; r<n; l++, r++) {
                if(s[l] < s[r]) {
                    swap(s[l], s[r]);
                    l++, r++;
                    swaps = true;
                }
            }
            time += swaps? 1: 0;
        } while(swaps);
        return time;
    }
};