class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> steps;
        for (auto log : logs) {
            if (!steps.empty() &&log == "../"){
                steps.pop();
            } else if (log == "./");
            else if (log != "../") {
                steps.push(log);
            }
        }
        return steps.size();
    }
};