class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream sva(version1), svb(version2);
        string token, tokenb;
        while(getline(sva, token, '.') 
              && getline(svb, tokenb, '.')) {
            if(stoi(token) > stoi(tokenb)) {
                return 1;
            } else if(stoi(token) < stoi(tokenb)) {
                return -1;
            }
            token = tokenb = "";
        }
        while(token.size() > 0 || getline(sva, token, '.')) {
            if(stoi(token) != 0) return 1;
            token = "";
        }
        while(tokenb.size() > 0 || getline(svb, tokenb, '.')) {
            if(stoi(tokenb) != 0) return -1;
            tokenb = "";
        }
        return 0;
    }
};