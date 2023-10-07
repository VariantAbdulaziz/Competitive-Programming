#include <bits/stdc++.h>
#define int int64_t
#define all(a) a.begin(), a.end()
#define range(a, f, t) a.begin() + f, a.begin() + t

using namespace std;

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    map<int, int> book;
    vector<int> as(n);
    for(auto &c: as) cin >> c;
    int runll = 0, runl = 0, l = 0, ll = 0, ans = 0;
    for(int r=0; r<n; r++) {
        runl += as[r];
        runll += as[r];
        while(runl >= a) {
            runl -= as[l++];
        }
        while(runll > b) {
            runll -= as[ll++];
        }
        ans += l - ll;
    }
    // int run = 0, ans = 0;
    // book[0] = 0;
    // for(int i=0; i<n; i++) {
    //     run += as[i];
    //     book[run] = i + 1;
    //     auto itera = book.lower_bound(run - a + 1);
    //     auto iterb = book.lower_bound(run - b);
    //     ans += (*itera).second - (*iterb).second;
    // }
    cout << ans << endl;
}

int32_t main(){
    solve();
}
