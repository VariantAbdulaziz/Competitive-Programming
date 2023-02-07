class Solution {
public:
    int minOperations(vector<string>& logs) {
        int min_operations = 0;
        for (auto log : logs) {
            if (min_operations && log == "../"){
                min_operations--;
            } else if (log == "./");
            else if (log != "../") {
                min_operations++;
            }
        }
        return min_operations;
    }
};