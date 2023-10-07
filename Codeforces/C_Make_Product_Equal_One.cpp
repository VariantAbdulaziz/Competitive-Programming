#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dp(map<pair<ll, int>, ll>& cache,vector<ll>& a, int n, int i,int prod){
    if(i == n && prod == 1) return 0;
    if(i == n) return 10e16;
    if(cache.find({i, prod}) != cache.end()) return cache[{i, prod}];
    ll r = min(abs(1 - a[i]) + dp(cache, a, n, i+1, prod),
                abs(-1 - a[i]) + dp(cache, a, n, i+1, -prod));
    cache.insert({{i, prod}, r});
    return r;
}

void solve(){
    int n; cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    map<pair<ll, int>, ll> cache;
    cout << dp(cache, a, n, 0, 1);
}

int main(){
    solve();
}