#include <bits/stdc++.h>
#define int64_t int

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &aj: a){
        cin >> aj;
    }
    sort(begin(a), end(a));
    int result = n / 2;
    for(int i=0, j; i<n; i=j){
        j = i;
        while(a[j] == a[i]){
            j++;
        }
        // cout << ">>" << i << " " << j << " " << a[i] << " " << (j - i) << endl;
        result = max(result, j * (n - j));
    }
    cout << result << endl;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}