class Solution {
public:
    int calculate(string s) {
        long num = 0, sign = 1, run = 0;
        stack<int> book;
        for(auto ch: s) {
            if(isdigit(ch)) {
                num = num * 10 + ch - '0';
            } else if(ch == '-' || ch == '+') {
                run += sign * num;
                sign = ch == '-'? -1: 1;
                num = 0;
            } else if (ch == '(') {
                book.push(run);
                book.push(sign);
                run = 0;
                sign = 1;
            } else if (ch == ')') {
                run += sign * num;
                run *= book.top(); book.pop();
                run += book.top(); book.pop();
                num = 0;
            }
        }
        run += sign * num;
        return run;
    }
};