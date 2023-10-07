#include <bits/stdc++.h>
#define int int64_t

using namespace std;

void solve(){
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for(auto &aj: a) cin >> aj;
    int run = 0, streak = 0, l = 0;
    for (int r=0; r < n; r++) {
        run += a[r];
        while(l < n && run > s)
            run -= a[l++];
        
        streak = max(streak, r - l + 1);
    }
    cout << streak;
}

int32_t main(){
    solve();
}
