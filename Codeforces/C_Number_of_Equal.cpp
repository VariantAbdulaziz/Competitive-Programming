#include <bits/stdc++.h>
#define int int64_t

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(auto &aj: a) cin >> aj;
    for(auto &bj: b) cin >> bj;

    int l = 0, r = 0, count = 0;
    while(l < n && r < m) {
        int now = a[l] < b[r]? a[l]: b[r];
        int lpivot = l, rpivot = r;
        while(l < n && now == a[l]) l++;
        while(r < m && now == b[r]) r++;
        count += (l - lpivot) * (r - rpivot);
    }
    cout << count;
}

int32_t main(){
    solve();
}
