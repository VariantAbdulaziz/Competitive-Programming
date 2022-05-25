// source: https://leetcode.com/problems/climbing-stairs/

// strategy: recursion | memoization
class Solution {
private:
    unordered_map<int, int> cache;
    int climb(int i, int n){
        if(cache.find(i) != cache.end())
            return cache[i];
        if(i > n)
            return 0;
        if(i == n)
            return 1;
        int res = climb(i+1, n) + climb(i+2, n);
        cache[i] = res;
        return res;
    }
public:
    int climbStairs(int n) {
        return climb(0, n);
    }
};