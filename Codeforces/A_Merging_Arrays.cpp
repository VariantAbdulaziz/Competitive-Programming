#include <bits/stdc++.h>
#define int int64_t

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), merged(n + m);
    for(auto &aj: a) cin >> aj;
    for(auto &bj: b) cin >> bj;
    int l = 0, r = 0, tail = 0;
    while(l < n || r < m) {
        if(l < n && r < m && a[l] < b[r]) {
            merged[tail] = a[l++];
        } else if (l < n && r < m) {
            merged[tail] = b[r++];
        } else {
            merged[tail] = l < n? a[l++]: b[r++];
        }
        tail++;
    }
    for(auto mj: merged) {
        cout << mj << " ";
    }
}

int32_t main(){
    solve();
}
