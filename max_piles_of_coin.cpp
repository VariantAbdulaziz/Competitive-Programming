// source: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/submissions/

// strategy: sorting
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int res{};
        
        for(int j = piles.size() - 1;j >= piles.size()/3; j-=2){
            res+=piles[j - 1];
        }
        return res;
    }
};