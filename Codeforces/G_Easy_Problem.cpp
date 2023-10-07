#include <bits/stdc++.h>

using namespace std;
typedef long long lli;

const string hard = "hard";

lli dp(vector<vector<lli>>& cache, vector<lli>& cost, string& s, int l, int r){
    if(r == 4) return LLONG_MAX;
    if(l == cost.size()) return 0;

    auto& result = cache[l][r];
    if(result != 0) return result;

    result = LLONG_MAX;
    if(s[l] == hard[r]){
        result = min(result, dp(cache, cost, s, l+1, r+1));
        result = min(result, cost[l] + dp(cache, cost, s, l+1, r));
    }
    else result = min(result, dp(cache, cost, s, l+1, r));

    return result;
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<lli> cost(n);
    for(auto &c: cost) cin >> c;

    vector<vector<lli>> cache(n, vector<lli>(4));

    cout << dp(cache, cost, s, 0, 0);
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();
}