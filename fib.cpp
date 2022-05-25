// source: https://leetcode.com/problems/fibonacci-number/

// strategy: recurion
class Solution {
private:
    unordered_map<int, int> cache;
public:
    int fib(int n) {
        if(cache.find(n) != cache.end())
            return cache[n];
        if (n < 2)
            return n;
        int res = fib(n - 1) + fib(n - 2);
        cache[n] = res;
        return res;
    }
};