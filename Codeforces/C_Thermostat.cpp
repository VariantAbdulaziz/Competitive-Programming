#include <bits/stdc++.h>
#define int int64_t

using namespace std;

void solve(){
    int l, r, x, a, b;
    cin >> l >> r >> x >> a >> b;
    if(l == r && x != 0 && a != b){
        cout << -1;
    }else if(a == b){
        cout << 0;
    } else if(a - b >= x){
        cout << 1;
    }
    else if (b - a >= x){
        cout << 1;
    } else if (b - x >= l && a - x >= l){
        cout << 2;
    } else if (r - a >= x && r - b >= x){
        cout << 2;
    } else if (r - a >= x && b - l >= x) {
        cout << 3;
    } else if(a - l >= x && r - b >= x){
        cout << 3;
    } else {
        cout << -1;
    }
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}