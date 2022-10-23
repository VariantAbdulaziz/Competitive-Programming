class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int need[26] = {0};
        int window[26] = {0};
        
        for(auto ch: p) need[ch - 'a']++;
        for(int i=0; i<min(s.size(), p.size()-1); i++) window[s[i] - 'a']++;
        
        vector<int> result;
        for(int i=p.size()-1; i<s.size(); i++){
            
            window[s[i] - 'a']++;
            if(anagram(need, window)) result.push_back(i - p.size() + 1);
            window[s[i - p.size() + 1] - 'a']--;
        }
        return result;
    }
    
    bool anagram(int need[], int window[]){
        for(int i=0; i<26; i++){
            if(need[i] != window[i]) return false;
        }
        return true;
    }
};