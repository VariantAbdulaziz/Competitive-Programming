class Solution {
public:
    int MaxProfit(vector<int>& cache, vector<int>& prices, int buying_idx){
        if(buying_idx >= prices.size()) return 0;
        auto& result = cache[buying_idx];
        if(result != -1) return result;

        result = MaxProfit(cache, prices, buying_idx+1);
        for(int selling_idx=buying_idx+1; selling_idx < prices.size(); selling_idx++){

            result = max(result, prices[selling_idx] - prices[buying_idx]
                                + MaxProfit(cache, prices, selling_idx + 2));
        }
        return result;
    }

    int maxProfit(vector<int>& prices) {
        vector<int> cache(prices.size(), -1);
        
        int result = MaxProfit(cache, prices, 0);
        return result;
    }
};