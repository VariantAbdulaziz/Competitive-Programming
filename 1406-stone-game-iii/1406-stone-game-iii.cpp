class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> processed(n, vector<int>(2)), cache(n, vector<int>(2));
        
        auto dp = [&](auto&& dp, int start, int turn){
            if(start >= n)
                return 0;
            
            auto& res = cache[start][turn];
            if(processed[start][turn]) return res;
            
            processed[start][turn] = 1;
            res = turn? INT_MIN: INT_MAX;
            int curr = 0;
            for(int idx=start; idx < n && idx < start+3; idx++){
                curr += stoneValue[idx];
                res = turn? max(res, curr + dp(dp, idx+1, 1-turn)):
                            min(res, dp(dp, idx+1, 1-turn));
            }
            return res;
        };
        int total = 0;
        for(auto stone: stoneValue) total += stone;
        int alice_score = dp(dp, 0, 1);
        int bob_score = total - alice_score;
        return alice_score == bob_score? "Tie": alice_score > bob_score? "Alice": "Bob";
    }
};