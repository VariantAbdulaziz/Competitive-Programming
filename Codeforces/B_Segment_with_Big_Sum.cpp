#include <bits/stdc++.h>
#define int int64_t

using namespace std;

void solve(){
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for(auto &aj: a) cin >> aj;
    int run = 0, streak = n + 1;
    for(int r=0, l=0; r<n; r++) {
        run += a[r];
        while(l <= r && run >= s) {
            streak = min(streak, r - l + 1);
            run -= a[l++];
        }
    }
    streak = n + 1 == streak? -1: streak;
    cout << streak;
}

int32_t main(){
    solve();
}
