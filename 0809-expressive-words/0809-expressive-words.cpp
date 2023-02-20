class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int result = 0;
        for(auto &word: words) {
            int i = 0, j = 0;
            int n = s.size(), m = word.size();
            bool flag = true;
            while (flag && i<n && j<m) {
                if(s[i] != word[j])
                    flag = false;
                
                if(!flag) break;
                int cs = 1, cw = 1;
                while(i + 1 < n && s[i+1] == s[i]) {
                    i++;
                    cs++;
                }
                while(j + 1 < m && word[j+1] == word[j]) {
                    j++;
                    cw++;
                }
                i++; j++;
                if(cw > cs)
                    flag = false;
                else if (cw < cs && cs < 3)
                    flag = false;
            }
            flag = !(!flag || flag && (i < n || j < m));
            result += flag? 1: 0;
        }
        return result;
    }
};