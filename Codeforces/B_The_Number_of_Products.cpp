#include <bits/stdc++.h>
#define int int64_t

using namespace std;

const int N = 2e5 + 1;

int n;
int a[N];
int dp[N][2];

void read(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
}

void solve(){

    // base cases
    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++){
            if((a[i]<0? 1: 0) == j)
                dp[i][j] = 1;
            else
                dp[i][j] = 0;
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++){ // fix the state

            // push value
            if(i+1<n)
                dp[i+1][j ^ (a[i+1]<0? 1: 0)] += dp[i][j];
        }
    }

    int pos = 0, neg = 0;
    for(int i=0; i<n; i++){
        pos += dp[i][0];
        neg += dp[i][1];
    }
    printf("%lld %lld\n", neg, pos);
}

int32_t main(){

    read();
    solve();
}