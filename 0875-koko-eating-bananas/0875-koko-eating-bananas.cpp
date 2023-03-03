class Solution {
public:
    bool valid(vector<int>& piles, int k, int h) {
        long total = 0;
        for(auto pile: piles) {
            total += (pile + k - 1) / k;
        }
        return total <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int _max = *max_element(begin(piles), end(piles));
        int k = _max;
        for(int j=_max/2; j > 0; j /= 2) {
            while(k - j > 0 && valid(piles, k - j, h)) {
                k -= j;
            }
        }
        return k;
    }
};