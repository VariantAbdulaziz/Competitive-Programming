#include <bits/stdc++.h>
#define int int64_t
#define all(a) a.begin(), a.end()
#define range(a, f, t) a.begin() + f, a.begin() + t

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(auto &aj: a) cin >> aj;
    for(auto &bj: b) cin >> bj;

    bool toa = a[n-1] <= b[n-1];
    for(int i=0; i<n; i++) {
        int ai = a[i], bi = b[i];
        a[i] = toa? min(ai, bi): max(ai, bi);
        b[i] = toa? max(ai, bi): min(ai, bi);
    }
    // for(auto aj: a) cout << aj << " "; cout << endl;
    // for(auto bj: b) cout << bj << " "; cout << endl;
    if(*max_element(all(a)) == a[n-1] && *max_element(all(b)) == b[n-1]){
        puts("Yes");
    } else puts("No");
}

int32_t main(){
    int t;
    cin >> t;
    while(t--) solve();
}
