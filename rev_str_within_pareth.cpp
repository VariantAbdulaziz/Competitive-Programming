// source: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

// policy: deque
class Solution {
public:
    string reverseParentheses(string s) {
        vector<char> st;
        
        for(auto val: s){
            if(val != ')')
                st.push_back(val);
            else{
                queue<char> q;
                while(st.back() != '('){
                    q.push(st.back());
                    st.pop_back();
                }
                st.pop_back(); // pops the (
                while(!q.empty()){
                    st.push_back(q.front());
                    q.pop();
                }
            }
        }
        
        string res{st.begin(), st.end()};
        
        return res;
    }
};