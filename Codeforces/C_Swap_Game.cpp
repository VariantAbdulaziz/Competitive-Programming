#include <bits/stdc++.h>
#define int int64_t

using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    cin >> a[0];
    a[0]--;
    int min_0 = INT_MAX, min_1 = INT_MAX;
    for(int i=1; i<n; i++){
        cin >> a[i];
        if(a[i] < min_0){
            min_1 = min_0;
            min_0 = a[i];
        } else if(a[i] < min_1){
            min_1 = a[i];
        }
    }
    if(a[0] < min_0){
        cout << "Bob";
    } else cout << "Alice";
}
int32_t main(){
    int t; cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}