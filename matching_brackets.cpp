// source: https://leetcode.com/problems/valid-parentheses/

// policy: stack
class Solution {
public:
    bool isValid(string s) {
        map<char, char> brackets{{'(', ')'}, {'[', ']'}, {'{', '}'}};
        stack<char> aStack;
        
        for(auto bracket: s){
            
            if(!aStack.empty() 
               && brackets.find(aStack.top()) != brackets.end()
               && brackets[aStack.top()] == bracket ) {
                aStack.pop();
            } else aStack.push(bracket);
        }
        
        return aStack.empty();
    }
};