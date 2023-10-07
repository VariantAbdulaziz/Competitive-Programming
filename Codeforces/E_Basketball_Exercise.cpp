#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dp(vector<vector<ll>> &cache, vector<vector<ll>> &rows, int idx, int row_no){
    int n = rows[0].size();
    if(idx >= n) return 0;

    auto &result = cache[row_no][idx];
    if(result != -1) return result;
    
    result = max(result, dp(cache, rows, idx+1, row_no));
    result = max(result, rows[row_no][idx] + dp(cache, rows, idx+1, 1-row_no));
    return result;
}

void solve(){
    int n;
    cin >> n;
    vector<vector<ll>> rows(2, vector<ll>(n));
    for(int i=0; i<2; i++){
        for(int j=0; j<n; j++){
            cin >> rows[i][j];
        }
    }
    vector<vector<ll>> cache(2, vector<ll>(n, -1));
    cout << max(dp(cache, rows, 0, 0), dp(cache, rows, 0, 1));
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();
}
