#include <bits/stdc++.h>
#define int int64_t

using namespace std;

int inf = 1e18;
const int REST = 0, CONTEST = 1, GYM = 2;


void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &aj: a){
        cin >> aj;
    }
    vector<vector<int>> dp(n + 1, {0, 0, 0});
    // 0: rest, 1: no gym, contest 2: gym, no contest 3: both
    // 0: rest, 1: contest, 2: gym
    for(int i=0; i<n; i++){
        dp[i+1][0] = max(dp[i][0], max(dp[i][1], dp[i][2]));
        dp[i+1][1] = max(dp[i][0], dp[i][2]);
		if(a[i] == 1 || a[i] == 3)
            dp[i+1][1]++;
		dp[i+1][2] = max(dp[i][0], dp[i][1]);
		if(a[i] == 2 || a[i] == 3)
            dp[i+1][2]++;
    }
    cout << n - max(dp[n][0], max(dp[n][1], dp[n][2]));
}

int32_t main() {
    solve();
}