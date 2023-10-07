#include <bits/stdc++.h>
#define int int64_t
#define all(a) a.begin(), a.end()
#define range(a, f, t) a.begin() + f, a.begin() + t

using namespace std;
const int inf = 2e18;

void solve(){
    int x, ans = inf; cin >> x;
    for(int i=0; i<32; i++) {
        if(!(x & (1 << i))) continue;
        int run = (1 << i);
        

        for(int j=0; j<32; j++) {
            run |= (1 << i);
            if(run & x > 0 && run ^ x > 0)
                ans = min(run, ans);

            if(j != i) run &= ~(1 << j);
        }
    }
    cout << ans << endl;
}

int32_t main(){
    int t = 1;
    cin >> t;
    while(t--) solve();
}
