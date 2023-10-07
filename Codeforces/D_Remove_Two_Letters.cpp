#include <bits/stdc++.h>
#define int int64_t
#define all(a) a.begin(), a.end()
#define range(a, f, t) a.begin() + f, a.begin() + t

using namespace std;

void solve(){
    int n; cin >> n; 
    string s; cin >> s;
    int ans = 0;
    auto book = make_pair('_', '_');
    for(int i=1; i<n; i++) {
        if(book != make_pair(s[i - 1], s[i]) && book != make_pair(s[i], s[i - 1])) {
            book = {s[i], s[i-1]};
            ans++;
        }
    }
    cout << ans << endl;
}

int32_t main(){
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
