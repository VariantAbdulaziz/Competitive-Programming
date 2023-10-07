#include <bits/stdc++.h>
#define int int64_t

using namespace std;
const int INF = 5e18;

int n, p, q, r;

const int N = 1e5 + 1;
int a[N];
int dp[N][3];

void read(){
    cin >> n >> p >> q >> r;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
}
void solve(){

    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            dp[i][j] = -INF;
        }
    }
    for(int i=0; i<n; i++){ // fix the state
        
        dp[i][0] = max(dp[i][0], p * a[i]);
        dp[i][1] = max(dp[i][1], q * a[i] + dp[i][0]);
        dp[i][2] = max(dp[i][2], r * a[i] + dp[i][1]);
        dp[i+1][0] = max(dp[i+1][0], dp[i][0]);
        dp[i+1][1] = max(dp[i+1][1], dp[i][1]);
        dp[i+1][2] = max(dp[i+1][2], dp[i][2]);
    }
    cout << dp[n-1][2] << endl;
}

int32_t main(){
    read();
    solve();
}