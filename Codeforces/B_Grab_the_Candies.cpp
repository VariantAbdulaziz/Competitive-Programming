#include <bits/stdc++.h>
#define int int64_t
#define all(a) a.begin(), a.end()
#define range(a, f, t) a.begin() + f, a.begin() + t

using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    int odds = 0, even = 0;
    for(int i=0; i<n; i++) {
        int aj;
        cin >> aj;
        even += aj % 2? 0: aj;
        odds += (aj % 2)? aj: 0;
    }

    if(even > odds) puts("YES");
    else puts("NO");
}

int32_t main(){
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
