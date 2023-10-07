#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k, d;
    cin >> n >> k >> d;
    vector<vector<int>> dp(n + 2, {0, 0});
    const int mod = 1e9 + 7;
    
    dp[0][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++){ // fix the state
            for(int ki = 1; ki <= k; ki++){
                if(ki == d || j == 1){
                    dp[min(i + ki, n + 1)][1] += dp[i][j];
                    dp[min(i + ki, n + 1)][1] %= mod;
                } else {
                    dp[min(i + ki, n + 1)][0] += dp[i][j];
                    dp[min(i + ki, n + 1)][0] %= mod;
                }
            }
        }
    }
    cout << dp[n][1] << endl;
}