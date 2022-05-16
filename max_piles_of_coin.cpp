// source: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/submissions/

// policy: sorting
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int res{};
        
        for(int i{}, j = piles.size() - 2; i < piles.size()/3; i++, j-=2){
            res+=piles[j];
        }
        return res;
    }
};