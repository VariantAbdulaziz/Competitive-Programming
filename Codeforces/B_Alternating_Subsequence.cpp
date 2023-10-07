#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;


pair<int, ll> dp(map<vector<int>, pair<int, ll>>& cache, vector<ll>& a, int n, int i, int flag){
    if(i == n) return {0, 0};
    if(cache.count({i, flag})) return cache[{i, flag}];
    pair<int, ll> sofar = {0, 1e-10};
    for(int j=i; j<n; j++){
        if((flag && a[j] > 0) || (!flag && a[j] < 0)){
            auto advance = dp(cache, a, n, j+1, 1-flag);
            advance.second+=a[j];
            advance.first+=1;
            if(advance > sofar) sofar = advance;
        }
    }
    cache[{i, flag}] = sofar;
    return sofar;
}

void solve(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        map<vector<int>, pair<int, ll>> cache;
        pair<int, ll> pathA = dp(cache, a, n, 0, 0);
        pair<int, ll> pathB = dp(cache, a, n, 0, 1);
        if(pathA > pathB) swap(pathA, pathB);
        cout << pathB.second << endl;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}