#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dp(vector<vector<ll>>& cache, vector<ll>& a, int idx, int product){
    int n = a.size();
    if(idx >= n && product) return 0LL;
    if(idx >= n) return LLONG_MAX;

    auto &res = cache[idx][product];
    if(res != LLONG_MAX) return res;

    ll pick = dp(cache, a, idx+1, product);
    ll dont_pick = dp(cache, a, idx+1, 1-product);
    if(pick != LLONG_MAX) res = min(res, abs(1-a[idx]) + pick);
    if(dont_pick != LLONG_MAX) res = min(res, abs(-1-a[idx]) + dont_pick);
    return res;
}

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n);

    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    vector<vector<ll>> cache(n, {LLONG_MAX, LLONG_MAX});
    cout << dp(cache, a, 0, 1) << endl;
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    solve();
}
