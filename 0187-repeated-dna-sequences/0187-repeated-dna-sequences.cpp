#define range(c, a) (c).begin()+(a), (c).end()

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> book;
        vector<string> res;
        string window;
        for(int r=0; r < s.size(); r++){
            window += s[r];
            if(r >= 9){
                if (book.count(window) && book[window] == 1) res.push_back(window);
                book[window]++;
                window = {range(window, 1)};
            }
        }
        return res;
    }
};