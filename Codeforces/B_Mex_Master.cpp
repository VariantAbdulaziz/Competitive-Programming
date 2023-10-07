#include <bits/stdc++.h>
#define int int64_t
#define all(a) a.begin(), a.end()
#define range(a, f, t) a.begin() + f, a.begin() + t

using namespace std;
const int inf = 2e18;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &aj: a) cin >> aj;
    priority_queue<int, vector<int>, greater<>> q(begin(a), end(a));
    int last = inf;
    int ans = 0;
    while(!q.empty()) {
        
    }
    cout << ans;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
