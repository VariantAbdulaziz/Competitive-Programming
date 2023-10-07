#include <bits/stdc++.h>

using namespace std;


void solve(){
    int n; cin >> n;
    vector<int> r(n);
    for(auto &rj: r)
        cin >> rj;
    int m; cin >> m;
    vector<int> b(m);
    for(auto &bj: b)
        cin >> bj;

    vector<vector<int>> dp(n+2, vector<int>(m + 2, INT_MIN));
    
    dp[0][0] = 0;
    int result = 0;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            dp[i+1][j] = max(dp[i+1][j],  dp[i][j] + r[i]);
            dp[i][j+1] = max(dp[i][j+1], dp[i][j] + b[j]);
            result = max(result, dp[i][j]);
        }
    }
    cout << result << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}