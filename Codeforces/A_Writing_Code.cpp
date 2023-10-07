#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int n, m, b, mod;
    cin >> n >> m >> b >> mod;
    vector<int> a(n);

    for(auto &aj: a)
        cin >> aj;

    vector<vector<ll>> dp(m+1, vector<ll>(b+1));

    dp[0][0] = 1;

    for(int i=0; i<n; i++){
        vector<vector<ll>> new_dp(m+1, vector<ll>(b+1));
        for(int j=0; j<=m; j++){
            for(int k=0; k<=b; k++){
                if(i < (n-1)){
                    new_dp[j][k] += dp[j][k];
                    new_dp[j][k] %= mod;
                }
                if((j < m) && ((k+a[i]) <= b)){
                    dp[j + 1][k + a[i]] += dp[j][k];
                    new_dp[j][k] %= mod;
                }
            }
        }
        if(i < (n-1))
            dp = new_dp;
    }
    ll ans = 0;
    for(int k=0; k<=b; k++){
        ans += dp[m][k];
        ans %= mod;
    }
    cout << ans;

}