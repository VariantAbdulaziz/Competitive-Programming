class Solution {
    map<int, int> memo;
public:
    int tribonacci(int n) {
        if(n < 1) return 0;
        if(n < 3) return 1;
        auto& result = memo[n];
        if(result != 0) return result;
        result = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        return result;
    }
};