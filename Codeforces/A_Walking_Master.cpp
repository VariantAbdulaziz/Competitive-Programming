#include <bits/stdc++.h>
#define int int64_t
#define all(a) a.begin(), a.end()
#define range(a, f, t) a.begin() + f, a.begin() + t

using namespace std;

void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int dy = d - b;
    if (dy < 0 || a + dy < c){
        cout << -1;
        return;
    }
    dy += (dy + a - c);
    cout << dy;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--) {
        solve();
        cout << endl;
    }
}
