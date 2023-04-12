class Solution {
public:
    bool helper(string prev, string subsequent) {
        bool found = stoull(prev) == (stoull(subsequent) + 1ll);
        int n = subsequent.size();
        for(int len=1; len<n; len++) {
            string curr = subsequent.substr(0, len);
            string following = subsequent.substr(len);
            found = found || helper(curr, following) && stoull(prev) == (stoull(curr) + 1ll);
        }
        return found;
    }
    bool splitString(string s) {
        int n = s.size();
        for(int len=1; len<n; len++) {
            string curr = s.substr(0, len);
            string subsequent = s.substr(len);
            if(helper(curr, subsequent))
                return true;
        }
        return false;
    }
};