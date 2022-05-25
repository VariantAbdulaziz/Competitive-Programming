// source: https://leetcode.com/problems/sorting-the-sentence/

// strategy: sorting
class Solution {
public:
    string sortSentence(string s) {
        
        stringstream ss(s);
        vector<string> sv{};
        string curW = "";
        while(ss >> curW)
            sv.push_back(curW);
        sort(
            sv.begin(),
            sv.end(),
            [](const string& a, const string& b){
                return a.back() - '0' < b.back() - '0';
            }
        );
          
        string result = "";
        for(string word: sv){
            word.pop_back();
            result += word + " ";
        }
        result.pop_back();
        
        return result;
    }
};