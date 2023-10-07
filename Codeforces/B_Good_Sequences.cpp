#include <bits/stdc++.h>
#define int int64_t

using namespace std;
const int N = 1e5 + 1;

int n;
int a[N];
int dp[N];

void read(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
}

void solve(){

    // base cases
    for(int i=0; i<n; i++)
        dp[i] = 1;

    for(int i=0; i<n; i++){ // fix the state

        // push value
        for(int j=i+1; j<n; j++)
            if(gcd(a[j], a[i]) > 1){
                dp[j] = max(dp[j], dp[i] + 1);
                break;
            }
    }

    int ans = 1;
    for(int i=0; i<n; i++){
        ans = max(ans, dp[i]);
    }
    printf("%lld\n", ans);
    
}

int32_t main(){

    read();
    solve();
}