class Solution {
public:
    bool divisorGame(int n) {
        const int BOB = 0, ALICE = 1;
        vector<deque<bool>> dp(n+1, deque<bool>(2, false));
        
        // base case
        dp[1][BOB] = true;
        
        for(int i=2; i<=n; i++){
            for(int turn=0; turn<2; turn++){ // fix the state
                
                bool bob = true;
                bool alice = false;
                for(int x = i-1; x > 0; x--){
                    if(i%x == 0){
                        bob = bob && dp[i-x][!turn];
                        alice = alice || dp[i-x][!turn];
                    }
                }
                dp[i][turn] = (turn == BOB? bob: alice);
            }
        }
        
        return dp[n][ALICE];
    }
};