class Solution {
public:
    bool detectCapitalUse(string word) {
        bool all_lower = true, all_upper = true;
        for(int i=1; i<word.size(); i++){
            all_upper = all_upper && isupper(word[i]);
            all_lower = all_lower && islower(word[i]);
        }
        return all_lower || (all_upper && isupper(word[0]));
    }
};