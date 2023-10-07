#include <bits/stdc++.h>
#define int int64_t

using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &aj: a) cin >> aj;

    int ones = 0, zeros = 0;
    vector<pair<int, int>> prefix(n + 1, {0, 0}), suffix(n + 1, {0, 0});
    for(int i=0; i<=n; i++){
        prefix[i] = {zeros, ones};
        if (i < n) {
            ones += a[i];
            zeros += 1-a[i];
        }
    }
    ones = 0, zeros = 0;
    for(int i=n; i>=0; i--){
        suffix[i] = {zeros, ones};
        if (i < n) {
            ones += a[i];
            zeros += 1-a[i];
        }
    }
    int inversions = 0;
    for(int i=0; i<n; i++){
        if (a[i]){
            inversions += suffix[i].first;
        }
    }
    int result = inversions;
    for ( int i=0; i<n; i++){
        if(a[i]){
            result = max(result, inversions - suffix[i].first + prefix[i].second);
        } else {
            result = max(result, inversions + suffix[i].first - prefix[i].second);
        }
    }
    cout << result;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}