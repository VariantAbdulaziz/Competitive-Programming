class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        map<char, char> book;
        for(int i=0; i<n; i++){
            if(book.find(t[i]) != book.end() && book[t[i]] != s[i]) {
                return false;
            }
            book[t[i]] = s[i];
        }
        book.clear();
        for(int i=0; i<n; i++){
            if(book.find(s[i]) != book.end() && book[s[i]] != t[i]) {
                return false;
            }
            book[s[i]] = t[i];
        }
        return true;
    }
};