#include <bits/stdc++.h>
#define int int64_t

using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    if(n == 0) {
        cout << 0;
        return;
    }
    int l, r;
    for(l = 0, r = n - 1; l < r && s[l] != s[r]; l++, r--);
    cout << r - l + 1;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}