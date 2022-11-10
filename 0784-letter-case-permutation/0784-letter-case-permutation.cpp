class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        backtrack(result, s, 0, "");
        return result;
    }
private:
    void backtrack(vector<string>& result, string& s, int idx, string path){
        if(idx > s.size()){
            result.push_back(path);
        } else if(isalpha(s[idx])){
            backtrack(result, s, idx+1, path + char(toupper(s[idx])));
            backtrack(result, s, idx+1, path + char(tolower(s[idx])));
        } else {
            backtrack(result, s, idx+1, path + s[idx]);
        }
    }
};