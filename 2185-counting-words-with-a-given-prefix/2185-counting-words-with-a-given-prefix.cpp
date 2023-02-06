class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int prefix_count = 0;
        for (auto &word: words) {
            if (word.size() >= pref.size() &&
                word.substr(0, pref.size()) == pref) {
                prefix_count++;
            }
        }
        
        return prefix_count;
    }
};