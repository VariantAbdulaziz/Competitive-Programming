#include <bits/stdc++.h>
#define int int64_t
#define all(a) a.begin(), a.end()
#define range(a, f, t) a.begin() + f, a.begin() + t

using namespace std;

void solve(){
    int n, q, i = 1;
    cin >> n >> q;
    vector<int> a(n), book(n + 1);
    for(auto &aj: a) {
        cin >> aj;
        book[i] = aj + book[i - 1];
        i++;
    }
    while(q--) {
        int l, r, k;
        cin >> l >> r >> k;
        int total = book[n];
        int out = book[r] - book[l - 1];
        int result = total - out + (r - l + 1) * k;
        if(result % 2) puts("YES");
        else puts("NO");
    }
}

int32_t main(){
    int t;
    cin >> t;
    while(t--) solve();
}
