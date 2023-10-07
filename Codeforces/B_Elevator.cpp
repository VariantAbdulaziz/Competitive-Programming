#include <bits/stdc++.h>
#define int int64_t
#define all(a) a.begin(), a.end()
#define range(a, f, t) a.begin() + f, a.begin() + t

using namespace std;

const int inf = 1e9;

void solve(){
    int w, et, ef;
    cin >> w >> et >> ef;
    int ans = 4 * w;
    for(int i=0; i<=4; i++) {
        int tocurr = et * abs(i - ef);
        ans = min(ans, tocurr + et * (4 - i) + i * w);
    }
    cout << ans << endl;
}

int32_t main(){
    int t; cin >> t;
    while(t--) solve();
}
