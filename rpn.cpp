// source: https://leetcode.com/problems/evaluate-reverse-polish-notation

// strategy: stack
class Solution {
public:
    int compute(int l, int r, string op){
        if(op == "+") 
            return l + r;
        else if(op == "-") 
            return l - r;
        else if(op == "*") 
            return l * r;
        else
            return l / r;
    }
    int evalRPN(vector<string>& tokens) {
        set<string> ops{"+", "-", "*", "/"};
        stack<int> aStack;
        for(auto token: tokens){
            
            if(ops.count(token)){
                int r = aStack.top(); aStack.pop();
                int l = aStack.top(); aStack.pop();
                aStack.push(compute(l, r, token));
            } else aStack.push(stoi(token));
        }
        return aStack.top();
    }
};