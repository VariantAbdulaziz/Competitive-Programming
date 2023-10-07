#include <bits/stdc++.h>
#define int int64_t

using namespace std;

void solve(){
    int l, r;
    cin >> l >> r;
    int result = 0;
    for(int i = 0; i < 64; i++) {
        int bit = (1 << i) - 1;
        while(bit < r) {
            int popcount = __builtin_popcount(bit);
            if(bit >= l)
                result = max(popcount, result);
            bit = bit << 1;
        }
    }

    cout << bitset<8>(3 << 1) << endl;
    cout << result;
}

int32_t main(){
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
